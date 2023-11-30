#pragma once
#include <initializer_list>

template <typename T>
class List
{
	private:
		int size;
		int cur;
		T *data;
		List<T> &swap(int i, int j);

	public:
		List();
		List(const List &obj);
		List(const std::initializer_list<T> &values);
		~List();
		List<T> &operator=(const List<T> &obj);

		bool empty() const;
		const T &peek() const;
		const T &operator[](int i) const;
		int find(const T &value) const;
		List<T> &push(const T &value);
		List<T> &push(const std::initializer_list<T> &values);
		List<T> &push(const List<T> &obj);
		List<T> &intersect(const List<T> &obj);
		List<T> &pop();
		List<T> &pop(int i);
		List<T> &pop(int i, int j);
		List<T> &pop(const std::initializer_list<T> &values);
		List<T> &replace(int i, const T &value);
		List<T> &replace(
				const std::initializer_list<int> &is,
				const std::initializer_list<T> &values);

		const T *begin() const;
		const T *end() const;
};

#include "List.tcc"
