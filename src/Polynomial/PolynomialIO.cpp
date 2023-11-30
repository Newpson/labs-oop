#include "PolynomialIO.hpp"
#include "Polynomial.hpp"
#include <regex>
#include <iostream>
#include <format>

void Polynomial::str_init(std::string _str)
{
	std::string str;
	for (char i: _str)
	{
		if ((i >= '0' && i <= '9') || i == '.' ||
				i == '+' || i == '-' ||
				i == 'x' || i == '^')
		{
			str += i;
		}
	}

	if (str[0] != '-')
	{
		str.insert(0, "+");
	}

	static const std::string monomial = "([+-](([0-9](\\.[0-9]+)?)+x?|x)(\\^([0-9]+))?)";
	static const std::regex rpoly(monomial+"+");
	static const std::regex rmono(monomial);

	std::smatch m;
	std::regex_search(str, m, rpoly);
	if (m.prefix().length() == 0 && m.suffix().length() == 0)
    {
		for (; std::regex_search(str, m, rmono); str = m.suffix())
        {
			int _n = 0;
			float _k = 0;

			/* get degree */
			if (m[6].length() == 0)
			{
				if (m[2].str().back() != 'x')
				{
					_n = 0;
				}
				else
				{
					_n = 1;
				}
			}
			else
			{
				_n = std::strtol(m[6].str().c_str(), NULL, 10);
			}

			/* change degree of current poly */
			if (_n > n)
			{
				realloc(_n);
			}

			/* get coefficient */
			if (m[2].str() == "x")
			{
				_k = 1;
			}
			else
			{
				_k = std::strtof(m[2].str().c_str(), NULL);
			}

			/* get sign */
			if (m[1].str()[0] == '-')
			{
				_k = -_k;
			}
			ks[_n] += _k;
        }
    }
}

std::string Polynomial::to_string(void) const
{
	std::string str = "";
	if (n == 0 && ks[0] == 0)
	{
		str = "0";
	}
	else
	{
		for (int i = 0; i < n+1; ++i)
		{
			if (ks[i] != 0)
			{
				if (i > 0)
				{
					if (!str.empty())
					{
						str += (ks[i] > 0 ? " + " : " - ");
					}
					if (ks[i] != 1)
					{
						str += std::format("{}", std::abs(ks[i]));
					}
					str += "x";
					if (i > 1)
					{
						str += "^" + std::format("{}", i);
					}
				}
				else
				{
					str += std::format("{}", ks[i]);
				}
			}
		}
	}
	return str;
}

std::ostream& operator<<(std::ostream& out, const Polynomial &p)
{
    out << p.to_string();
    return out;
}

std::istream& operator>>(std::istream& in, Polynomial &p)
{
	std::string str;
	std::getline(in, str);
	p = Polynomial(str);
    return in;
}
