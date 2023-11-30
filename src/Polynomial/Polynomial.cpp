#include "Polynomial.hpp"
#include <algorithm>
#include <string>
#include <cstdlib>

Polynomial::Polynomial(void): n(0)
{
	ks = new float[1] {0};
}

Polynomial::Polynomial(int n): n(n)
{
	ks = new float[n+1] {0};
}

Polynomial::Polynomial(std::string str): n(0)
{
	ks = new float[n+1];
	ks[n] = 0;
	str_init(str);
}

Polynomial::Polynomial(const Polynomial &p): n(p.n)
{
	ks = new float[n+1];
	std::copy_n(p.ks, n+1, ks);
}

Polynomial::~Polynomial(void)
{
	delete[] ks;
}

void Polynomial::realloc(int n)
{
	float *_ks = new float[n+1] {0};
	std::copy_n(ks, n > this->n ? this->n+1 : n+1, _ks);
	this->n = n;
	delete[] ks;
	ks = _ks;
}

Polynomial &Polynomial::operator=(const Polynomial &p)
{
	if (&p != this)
	{
		realloc(p.n);
		std::copy_n(p.ks, n+1, ks);
	}
	return (*this);
}

Polynomial Polynomial::operator-(void) const
{
	Polynomial p(*this);
	for (int i = 0; i < n+1; ++i)
	{
		p.ks[i] = -ks[i];
	}
	return p;
}

Polynomial Polynomial::operator+(const Polynomial &p)
{
	const Polynomial &higher = (n > p.n ? (*this) : p);
	const Polynomial &lower = (n > p.n ? p : (*this));
	Polynomial _p(higher);
	for (int i = 0; i < n+1; ++i)
	{
		_p.ks[i] += lower.ks[i];
	}
	return _p;
}

Polynomial Polynomial::operator-(const Polynomial &p)
{
	return ((*this) + (-p));
}

Polynomial Polynomial::operator*(const Polynomial &p)
{
	Polynomial _p(n+p.n);
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < p.n+1; ++j)
		{
			_p.ks[i+j] += ks[i] * p.ks[j];
		}
	}
	return _p;
}

bool Polynomial::operator>(const Polynomial &p) const
{
	return (n > p.n);
}

bool Polynomial::operator<(const Polynomial &p) const
{
	return (n < p.n);
}
