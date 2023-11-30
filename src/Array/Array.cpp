#include "Array.hpp"
#include "Set.hpp"
#include <initializer_list>
#include <ostream>

Array::Array() {}
Array::Array(const std::initializer_list<double> &list):
	data(list) {}
Array::Array(const Set &data):
	data(data) {}
Array::Array(const Array *obj):
	Array(obj->data) {}
Array::~Array()
{}

int Array::size() const
{
	return data.size();
}

void Array::insert(double k)
{
	data.insert(k);
}

void Array::erase(double k)
{
	data.erase(k);
}

std::ostream &operator<<(std::ostream &out, const Array *obj)
{
	for (double i: obj->data)
	{
		out << i << " ";
	}
	return out;
}
