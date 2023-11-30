#include "Rational.hpp"
#include <iostream>

int main()
{
	Rational a(3, 9);
	Rational b(2, 12);
	Rational z(0);
	Pair c(5, 6);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << "a + b = " << (a+b) << std::endl;
	std::cout << "a - b = " << (a-b) << std::endl;
	std::cout << "a * b = " << (a*b) << std::endl;
	std::cout << "a * z = " << (a*z) << std::endl;
	std::cout << "a / b = " << (a/b) << std::endl;
	std::cout << "a / z = " << (a/z) << std::endl;
	std::cout << "a > b: " << (a>b) << std::endl;
	std::cout << "a < b: " << (a<b) << std::endl;
	std::cout << "a == b: " << (a==b) << std::endl;
	std::cout << "a != b: " << (a!=b) << std::endl;
	return 0;
}
