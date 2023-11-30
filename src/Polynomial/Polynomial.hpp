#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <string>

class Polynomial
{
	int n;
	float *ks;

	Polynomial(int n);

	void realloc(int n);
	void str_init(std::string str);

	public:
		Polynomial(void);
		Polynomial(std::string str);
		Polynomial(const Polynomial &p);
		~Polynomial(void);

		std::string to_string(void) const;
		Polynomial &operator=(const Polynomial &p);
		Polynomial operator-(void) const;
		Polynomial operator+(const Polynomial &p);
		Polynomial operator-(const Polynomial &p);
		Polynomial operator*(const Polynomial &p);
		bool operator<(const Polynomial &p) const;
		bool operator>(const Polynomial &p) const;
};

#endif /* POLYNOMIAL_HPP */
