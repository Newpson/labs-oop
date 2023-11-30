#pragma once
#include "Fraction.hpp"
#include <iostream>
#include <string>

class Money
{
	Fraction money;
	Money(const Fraction &frac);
	
	public:
		Money(const double flp);
		Money(const Money &obj);
		Money &operator=(const Money &obj);

		Money operator+(const Money &obj) const;
		Money &operator+=(const Money &obj);
		Money operator-() const;
		Money operator-(const Money &obj) const;
		Money &operator-=(const Money &obj);
		Money operator*(const double k) const;
		Money operator/(const double k) const;
		double operator/(const Money &obj) const;

		bool operator>(const Money &obj) const;
		bool operator<(const Money &obj) const;
		bool operator==(const Money &obj) const;
		bool operator!=(const Money &obj) const;
		bool operator>=(const Money &obj) const;
		bool operator<=(const Money &obj) const;

		int32_t get_rub() const;
		int8_t get_kop() const;

		std::string to_string() const;

		friend std::ostream &operator<<(std::ostream &out, const Money &obj);
};
