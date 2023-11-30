#include "Fraction.hpp"
#include <iostream>

/*
 * division
 *
 * 34.125
 * 100010.001
 *
 * 12.625
 * 1100.101
 * 
 * 2.544554455
 * 10.10001011011001111111
 */
int main()
{
	Fraction f1(34.125);
	Fraction f2(12.625);
	std::cout << (f1*f2) << std::endl;
	return 0;
}
