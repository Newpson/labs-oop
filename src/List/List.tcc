#pragma once
/* List.hpp */
#include <initializer_list>
#include <algorithm>
#include <cstdlib>
#include <iostream>

template <typename T>
List<T>::List():
	size(1),
	cur(-1),
	data((T *) malloc(sizeof(T)))
{}

template <typename T>
List<T>::List(const std::initializer_list<T> &values):
	size(values.size()),
	cur(-1)
{
	if (size == 0)
	{
		size = 1;
	}
	data = (T *) malloc(size*sizeof(T));
	push(values);
}

template <typename T>
List<T>::List(const List<T> &obj):
	size(obj.size),
	cur(obj.cur),
	data((T *) malloc(obj.size*sizeof(T)))
{
	std::copy_n(obj.data, size, data);
}

template <typename T>
List<T>::~List()
{
	free(data);
	data = nullptr;
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &obj)
{
	free(data);
	size = obj.size;
	cur = obj.cur;
	data = (T *) malloc(size*sizeof(T));
	std::copy_n(obj.data, size, data);
	return *this;
}

template <typename T>
bool List<T>::empty() const
{
	return cur < 0;
}

template <typename T>
const T &List<T>::peek() const
{
	return data[cur];
}

template <typename T>
const T &List<T>::operator[](int i) const
{
	return data[i];
}

template <typename T>
int List<T>::find(const T &value) const
{
	for (int i = 0; i <= cur; ++i)
	{
		if (value == data[i])
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
List<T> &List<T>::push(const T &value)
{
	if (find(value) < 0)
	{
		++cur;
		if (cur == size)
		{
			size *= 2;
			data = (T *) std::realloc(data, size*sizeof(T));
		}
		data[cur] = value;
	}
	return *this;
}

template <typename T>
List<T> &List<T>::push(const std::initializer_list<T> &values)
{
	for (const T &value: values)
	{
		push(value);
	}
	return *this;
}

template <typename T>
List<T> &List<T>::push(const List<T> &obj)
{
	for (const T &value: obj)
	{
		push(value);
	}
	return *this;
}

template <typename T>
List<T> &List<T>::intersect(const List<T> &obj)
{
	List<T> temp;
	for (const T &value: *this)
	{
		if (obj.find(value) >= 0)
		{
			temp.push(value);
		}
	}
	*this = temp;
	return *this;
}

template <typename T>
List<T> &List<T>::pop()
{
	--cur;
	return *this;
}

template <typename T>
List<T> &List<T>::pop(int i)
{
	swap(i, cur).pop();
	return *this;
}

template <typename T>
List<T> &List<T>::pop(int i, int j)
{
	for (int _i = i; _i < j; ++_i)
	{
		pop(_i);
	}
	return *this;
}

template <typename T>
List<T> &List<T>::pop(const std::initializer_list<T> &values)
{
	for (const T &value: values)
	{
		int i = find(value);
		if (i > 0)
		{
			pop(i);
		}
	}
	return *this;
}

template <typename T>
List<T> &List<T>::swap(int i, int j)
{
	if (i != j)
	{
		T temp(data[i]);
		data[i] = data[j];
		data[j] = temp;
	}
	return *this;
}

template <typename T>
const T *List<T>::begin() const
{
	return data;
}

template <typename T>
const T *List<T>::end() const
{
	return data+cur+1;
}

template <typename T>
List<T> &List<T>::replace(int i, const T &value)
{
	if (find(value) < 0)
	{
		data[i] = value;
	}
	else
	{
		pop(i);
	}
	return *this;
}

template <typename T>
List<T> &List<T>::replace(
		const std::initializer_list<int> &is,
		const std::initializer_list<T> &values)
{
	int *i = is.begin();
	int *value = values.begin();
	for (int _i = 0; _i < is.size(); ++_i, ++i, ++values)
	{
		replace(*i, *value);
	}
	return *this;
}
