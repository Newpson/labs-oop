#include "Set.hpp"
#include <initializer_list>
#include <cstdlib>
#include <algorithm>

Set::Set():
	length(0),
	data(nullptr)
{}

Set::Set(std::initializer_list<double> list):
	Set()
{
	for (double k: list)
	{
		insert(k);
	}
}

Set::Set(const Set &obj):
	length(obj.length),
	data((double *) malloc(obj.length*sizeof(double)))
{
	std::copy_n(obj.data, length, data);
}

Set::~Set()
{
	free(data); /* free() is required because realloc() is used */
	data = nullptr;
}

void Set::insert(double k)
{
	if (!contains(k))
	{
		data = (double *) std::realloc(data, (length+1)*sizeof(double));
		data[length] = k;
		++length;
	}
}

void Set::swap(int i, int j)
{
	if (i != j)
	{
		double temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
}

void Set::erase(double k)
{
	if (contains(k))
	{
		for (int i = 0; i < length; ++i)
		{
			if (data[i] == k)
			{
				swap(i, length-1);
			}
		}
		data = (double *) std::realloc(data, (length-1)*sizeof(double));
		--length;
	}
}

void Set::merge(const Set &obj)
{
	for (double k: obj)
	{
		insert(k);
	}
}

int Set::size() const
{
	return length;
}

bool Set::contains(double k) const
{
	for (int i = 0; i < length; ++i)
	{
		if (data[i] == k) /* dummy */
		{
			return true;
		}
	}
	return false;
}


double *Set::begin() const
{
	return data;
}

double *Set::end() const
{
	return data + length;
}
