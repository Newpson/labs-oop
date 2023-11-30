#pragma once
#include "Set.hpp"
#include <initializer_list>
#include <ostream>

class Array
{
	protected:
		Set data;

	public:
		Array();
		Array(const std::initializer_list<double> &list);
		Array(const Set &data);
		Array(const Array *obj);
		virtual ~Array();

		int size() const;
		void insert(double k);
		void erase(double k);
		virtual Array *operator+(const Array *obj) const = 0;
		virtual double *foreach() const = 0;

		friend std::ostream &operator<<(std::ostream &out, const Array *obj);
};
