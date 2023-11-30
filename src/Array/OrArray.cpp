#include "OrArray.hpp"
#include "Set.hpp"
#include <initializer_list>
#include <cmath>

OrArray::OrArray():
	Array() {}
OrArray::OrArray(const std::initializer_list<double> &list):
	Array(list) {}
OrArray::OrArray(const Set &data):
	Array(data) {}
OrArray::OrArray(const OrArray *obj):
	Array(obj) {}

OrArray *OrArray::operator+(const Array *_obj) const
{
	OrArray *temp(new OrArray(data));
	temp->data.merge(dynamic_cast<const OrArray*>(_obj)->data);
	return temp;
}

double *OrArray::foreach() const
{
	double *res = new double[data.size()];
	int i = 0;
	for (double k: data)
	{
		res[i] = std::log(k);
		++i;
	}
	return res;
}
