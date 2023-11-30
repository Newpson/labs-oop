#pragma once

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <ostream>

class Fraction
{
	int64_t data;
	static constexpr size_t FRAC_SIZE = 4294967296;
	static constexpr size_t FRAC_BITS = 32;

	public:
		struct split_t
		{
			int32_t intg;
			uint32_t frac;
		};

	private:
		split_t unpack() const;
		Fraction(int64_t data);

	public:
		Fraction(const double flp);

		explicit operator double() const;
		Fraction operator=(const double flp);

		Fraction operator+(const Fraction &obj) const;
		Fraction &operator+=(const Fraction &obj);
		Fraction operator-() const;
		Fraction operator-(const Fraction &obj) const;
		Fraction &operator-=(const Fraction &obj);
		Fraction operator*(const Fraction &obj) const;
		/* Fraction operator/(const Fraction &obj) const; */

		bool operator>(const Fraction &obj) const;
		bool operator<(const Fraction &obj) const;
		bool operator==(const Fraction &obj) const;
		bool operator!=(const Fraction &obj) const;
		bool operator<=(const Fraction &obj) const;
		bool operator>=(const Fraction &obj) const;

		int32_t get_intg() const;
		double get_frac() const;

		friend std::ostream &operator<<(std::ostream &out, const Fraction &obj);
};

