#include "List.hpp"
#include <iostream>

template <typename T>
std::ostream &operator<<(std::ostream &out, const List<T> &list)
{
	for (const T &value: list)
	{
		out << value << " ";
	}
	return out;
}

int main()
{
	List<int> a({1, 2, 3, 5, 6, 7, 6, 6, 8, 9, 1, -15, 0, 0});
	List<int> b({1, 0, 99, 7474, -15});
	std::cout << "a: " << std::endl << a << std::endl;
	std::cout << "b: " << std::endl << b << std::endl;
	a.intersect(b);
	std::cout << "a ^= b: " << std::endl << a << std::endl;

	List<int> c({1, 2, 3, 8, 0, -45});
	List<int> d({1, 0, 16, -35});
	std::cout << "c: " << std::endl << c << std::endl;
	std::cout << "d: " << std::endl << d << std::endl;
	c.push(d);
	std::cout << "c v= d: " << std::endl << c << std::endl;

	std::cout << "Fancy iterated output" << std::endl;
	for (int value: d)
	{
		std::cout << ".-' " << value << " '-. ";
	}
	std::cout << std::endl;

	std::cout << "Braces!" << std::endl;
	std::cout << "b[0]+b[1]+b[2] = " <<  b[0] + b[1] + b[2] << std::endl;
	return 0;
}
