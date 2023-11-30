#include "Rational.hpp"
#include "Pair.hpp"
#include <string>
#include <format>
#include <ostream>
#include <cmath>

Rational &Rational::fix_null()
{
	if (b == 0)
	{
		b = 1;
	}
	return *this;
}

Rational::Rational(int a, int b): Pair(a, std::abs(b))
{
	fix_null().reduce();
}

Rational::Rational(const Rational &obj):
	Rational(obj.a, obj.b)
{}

Rational &Rational::operator=(const Rational &obj)
{
	a = obj.a;
	b = obj.b;
	return *this;
}

int Rational::gcd() const
{
	int ta = std::abs(a), tb = std::abs(b);
	while (ta != 0 && tb != 0)
	{
		if (ta > tb)
		{
			ta %= tb;
		}
		else
		{
			tb %= ta;
		}
	}
	return ta + tb;
}

Rational &Rational::reduce()
{
	int _gcd = gcd();
	a /= _gcd;
	b /= _gcd;
	return *this;
}

Rational Rational::operator+(const Rational &obj) const
{
	return Rational(a*obj.b + obj.a*b, b*obj.b);
}

Rational &Rational::operator+=(const Rational &obj)
{
	*this = *this + obj;
	return *this;
}

Rational Rational::operator-() const
{
	return Rational(-a, b);
}

Rational Rational::operator-(const Rational &obj) const
{
	return *this + -obj;
}

Rational &Rational::operator-=(const Rational &obj)
{
	*this += -obj;
	return *this;
}

Rational Rational::operator*(const Rational &obj) const
{
	Pair temp = Pair(*this) * obj;
	return Rational(temp.get_a(), temp.get_b());
}

Rational Rational::swap() const
{
	return Rational(std::copysign(b, a), std::copysign(a, b));
}

Rational Rational::operator/(const Rational &obj) const
{
	if (obj.a != 0)
	{
		return *this * obj.swap();
	}
	return Rational(0);
}

bool Rational::operator>(const Rational &obj) const
{
	return a*obj.b > obj.a*b;
}

bool Rational::operator>=(const Rational &obj) const
{
	return *this > obj || *this == obj;
}

bool Rational::operator<(const Rational &obj) const
{
	return obj > *this;
}

bool Rational::operator<=(const Rational &obj) const
{
	return obj >= *this;
}


std::string Rational::to_string() const
{
	return std::format("{}/{}", a, b);
}

std::ostream &operator<<(std::ostream &out, const Rational &obj)
{
	out << obj.to_string();
	return out;
}
