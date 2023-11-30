#pragma once

#include "Pair.hpp"
#include <string>
#include <ostream>

class Rational: public Pair
{
	int gcd() const;
	Rational swap() const;
	Rational &fix_null();
	Rational &reduce();

	public:
		Rational(int a = 0, int b = 0);
		Rational(const Rational &obj);

		Rational &operator=(const Rational &obj);

		Rational operator+(const Rational &obj) const;
		Rational &operator+=(const Rational &obj);
		Rational operator-() const;
		Rational operator-(const Rational &obj) const;
		Rational &operator-=(const Rational &obj);
		Rational operator*(const Rational &obj) const;
		Rational operator/(const Rational &obj) const;

		bool operator>(const Rational &obj) const;
		bool operator>=(const Rational &obj) const;
		bool operator<(const Rational &obj) const;
		bool operator<=(const Rational &obj) const;

		std::string to_string() const;
		friend std::ostream &operator<<(std::ostream &out, const Rational &obj);
};

