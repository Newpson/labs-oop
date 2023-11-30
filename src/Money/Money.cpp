#include "Money.hpp"
#include "Fraction.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

Money::Money(const Fraction &frac): money(frac)
{}

Money::Money(const Money &obj): money(obj.money)
{}

Money::Money(const double flp):
	money(static_cast<double>(static_cast<int>(flp*100))/100)
{}

Money &Money::operator=(const Money &obj)
{
	money = obj.money;
	return *this;
}

Money Money::operator+(const Money &obj) const
{
	return Money(money + obj.money);
}

Money &Money::operator+=(const Money &obj)
{
	money += obj.money;
	return *this;
}

Money Money::operator-() const
{
	return Money(-money);
}

Money Money::operator-(const Money &obj) const
{
	return *this + -obj;
}

Money &Money::operator-=(const Money &obj)
{
	*this += -obj;
	return *this;
}

Money Money::operator*(const double k) const
{
	return Money(double(money)*k);
}

Money Money::operator/(const double k) const
{
	return Money(double(money)/k);
}

double Money::operator/(const Money &obj) const
{
	return double(money)/double(obj.money);
}

bool Money::operator>(const Money &obj) const
{
	return money > obj.money;
}

bool Money::operator<(const Money &obj) const
{
	return money < obj.money;
}

bool Money::operator==(const Money &obj) const
{
	return money == obj.money;
}

bool Money::operator!=(const Money &obj) const
{
	return !(*this == obj);
}

bool Money::operator>=(const Money &obj) const
{
	return money >= obj.money;
}

bool Money::operator<=(const Money &obj) const
{
	return money <= obj.money;
}

int32_t Money::get_rub() const
{
	return money.get_intg();
}

int8_t Money::get_kop() const
{
	return static_cast<int8_t>(money.get_frac()*100);
}

std::string Money::to_string() const
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << double(money);
	return std::string(stream.str());
}

std::ostream &operator<<(std::ostream &out, const Money &obj)
{
	out << obj.to_string();
	return out;
}
