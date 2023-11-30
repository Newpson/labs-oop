#pragma once

#include <string>
#include <ostream>

class Pair
{
	protected:
		int a;
		int b;

	public:
		Pair(int a = 0, int b = 0);
		Pair(const Pair &obj);

		Pair &operator=(const Pair &obj);

		Pair operator+(const Pair &obj) const;
		Pair &operator+=(const Pair &obj);
		Pair operator-() const;
		Pair operator-(const Pair &obj) const;
		Pair &operator-=(const Pair &obj);
		Pair operator*(const Pair &obj) const;

		bool operator==(const Pair &obj) const;
		bool operator!=(const Pair &obj) const;

		int get_a() const;
		int get_b() const;

		std::string to_string() const;
		friend std::ostream &operator<<(std::ostream &out, const Pair &obj);
};

