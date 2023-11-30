#pragma once
#include "Array.hpp"
#include "Set.hpp"
#include <initializer_list>

class AndArray: public Array
{
	public:
		AndArray();
		AndArray(const std::initializer_list<double> &list);
		AndArray(const Set &data);
		AndArray(const Array *obj);

		AndArray *operator+(const Array *obj) const;
		double *foreach() const;
};
