#pragma once
#include <initializer_list>

class Set
{
	int length;
	double *data;

	void swap(int i, int j);

	public:
		Set();
		Set(std::initializer_list<double> list);
		Set(const Set &data);
		Set(Set *obj);
		~Set();

		void insert(double k);
		void erase(double k);
		void merge(const Set &obj);
		int size() const;
		bool contains(double k) const;

		double *begin() const;
		double *end() const;
};
