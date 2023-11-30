#pragma once
#include "Array.hpp"
#include "Set.hpp"
#include <initializer_list>

class OrArray: public Array
{
	public:
		OrArray();
		OrArray(const std::initializer_list<double> &list);
		OrArray(const Set &data);
		OrArray(const OrArray *obj);

		OrArray *operator+(const Array *obj) const;
		double *foreach() const;
};
