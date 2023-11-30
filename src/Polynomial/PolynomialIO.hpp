#ifndef POLYNOMIALIO_HPP
#define POLYNOMIALIO_HPP

#include "Polynomial.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Polynomial &p);
std::istream& operator>>(std::istream& in, Polynomial &p);

#endif /* POLYNOMIALIO_HPP */
