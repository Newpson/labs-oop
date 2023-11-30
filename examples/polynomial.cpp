#include <iostream>
#include "Polynomial.hpp"
#include "PolynomialIO.hpp"

int main(void)
{
	Polynomial a, b;
	std::cin >> a;
	std::cin >> b;
	std::cout << (a+b) << std::endl;
	return 0;
}
