#include "Fraction.hpp"
#include <cstdint>
#include <cmath>
#include <ostream>

Fraction::Fraction(int64_t data): data(data)
{}

Fraction::Fraction(const double flp)
{
	double dintg, dfrac;
	dfrac = std::modf(std::abs(flp), &dintg);
	data =
		static_cast<int64_t>(dintg)<<FRAC_BITS |
		static_cast<uint32_t>(dfrac*FRAC_SIZE);
	data = std::copysign(data, flp);
}

Fraction::split_t Fraction::unpack() const
{
	return
		{
			static_cast<int32_t>(data>>FRAC_BITS),
			static_cast<uint32_t>(data&(FRAC_SIZE-1))
		};
}

Fraction::operator double() const
{
	split_t sdata = unpack();
	return
		static_cast<double>(sdata.intg) +
		static_cast<double>(sdata.frac)/FRAC_SIZE;
}

Fraction Fraction::operator=(const double flp)
{
	return Fraction(flp);
}

Fraction Fraction::operator+(const Fraction &obj) const
{
	return Fraction(data + obj.data);
}

Fraction &Fraction::operator+=(const Fraction &obj)
{
	*this = *this + obj;
	return *this;
}

Fraction Fraction::operator-() const
{
	return Fraction(-data);
}

Fraction Fraction::operator-(const Fraction &obj) const
{
	return *this + (-obj);
}

Fraction &Fraction::operator-=(const Fraction &obj)
{
	*this = *this - obj;
	return *this;
}

Fraction Fraction::operator*(const Fraction &obj) const
{
	split_t uthis = unpack();
	split_t uobj = obj.unpack();

	int64_t intg = static_cast<int64_t>(uthis.intg * uobj.intg) << FRAC_BITS;
	uint64_t frac = (static_cast<uint64_t>(uthis.frac) *
			static_cast<uint64_t>(uobj.frac)) >> FRAC_BITS;

	int64_t result = intg | frac;

	int64_t ifrac = static_cast<int64_t>(uthis.intg) *
		static_cast<uint64_t>(uobj.frac);
	int64_t fintg = static_cast<uint64_t>(uthis.frac) *
		static_cast<int64_t>(uobj.intg);

	result += ifrac + fintg;
	return Fraction(result);
}

bool Fraction::operator>(const Fraction &obj) const
{
	return data > obj.data;
}

bool Fraction::operator<(const Fraction &obj) const
{
	return obj > *this;
}

bool Fraction::operator==(const Fraction &obj) const
{
	return data == obj.data;
}

bool Fraction::operator!=(const Fraction &obj) const
{
	return !(*this == obj);
}

bool Fraction::operator>=(const Fraction &obj) const
{
	return data > obj.data || data == obj.data;
}

bool Fraction::operator<=(const Fraction &obj) const
{
	return obj >= *this;
}

int32_t Fraction::get_intg() const
{
	return unpack().intg;
}

double Fraction::get_frac() const
{
	return std::copysign(
			static_cast<double>(unpack().frac)/FRAC_SIZE,
			data);
}

std::ostream &operator<<(std::ostream &out, const Fraction &obj)
{
	out << double(obj);
	return out;
}
