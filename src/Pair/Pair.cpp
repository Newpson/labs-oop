#include "Pair.hpp"
#include <format>

Pair::Pair(int a, int b):
	a(a), b(b)
{}

Pair::Pair(const Pair &obj):
	a(obj.a), b(obj.b)
{}

Pair &Pair::operator=(const Pair &obj)
{
	a = obj.a;
	b = obj.b;
	return *this;
}

Pair Pair::operator+(const Pair &obj) const
{
	return Pair(a + obj.a, b + obj.b);
}

Pair &Pair::operator+=(const Pair &obj)
{
	*this = *this + obj;
	return *this;
}

Pair Pair::operator-() const
{
	return Pair(-a, -b);
}

Pair Pair::operator-(const Pair &obj) const
{
	return *this + -obj;
}

Pair &Pair::operator-=(const Pair &obj)
{
	*this += -obj;
	return *this;
}

bool Pair::operator==(const Pair &obj) const
{
	return a == obj.a && b == obj.b;
}

bool Pair::operator!=(const Pair &obj) const
{
	return !(*this == obj);
}

Pair Pair::operator*(const Pair &obj) const
{
	return Pair(a*obj.a, b*obj.b);
}

int Pair::get_a() const { return a; }
int Pair::get_b() const { return b; }

std::string Pair::to_string() const
{
	return std::format("({}, {})", a, b);
}

std::ostream &operator<<(std::ostream &out, const Pair &obj)
{
	out << obj.to_string();
	return out;
}
