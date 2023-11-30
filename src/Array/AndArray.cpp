#include "AndArray.hpp"
#include "Set.hpp"
#include <initializer_list>
#include <cmath>

AndArray::AndArray():
	Array() {}
AndArray::AndArray(const std::initializer_list<double> &list):
	Array(list) {}
AndArray::AndArray(const Set &data):
	Array(data) {}
AndArray::AndArray(const Array *obj):
	Array(obj) {}

AndArray *AndArray::operator+(const Array *_obj) const
{
	const AndArray *obj = dynamic_cast<const AndArray*>(_obj);
	AndArray *temp(new AndArray(data));

	for (double i: data)
	{
		if (!(temp->data.contains(i) && obj->data.contains(i)))
		{
			temp->data.erase(i);
		}
	}
	return temp;
}

double *AndArray::foreach() const
{
	double *res = new double[data.size()];
	int i = 0;
	for (double k: data)
	{
		res[i] = std::sqrt(k);
		++i;
	}
	return res;
}
