#include "AndArray.hpp"
#include "OrArray.hpp"
#include <iostream>

int main()
{
	Array *result = nullptr;

	Array *anda = new AndArray({1, 2, -3, 4, 5});
	Array *andb = new AndArray({1, 3, 3, 0, 5});
	std::cout << "AND" << std::endl;
	std::cout << "a:\t" << anda << std::endl;
	std::cout << "b:\t" << andb << std::endl;
	result = *anda+andb;
	std::cout << "a+b:\t" << result << std::endl;
	delete andb; andb = nullptr;
	delete result; result = nullptr;

	Array *ora = new OrArray({1, 2, -3, 4, 5});
	Array *orb = new OrArray({1, 3, 3, 0, 5});
	std::cout << "OR" << std::endl;
	std::cout << "a:\t" << ora << std::endl;
	std::cout << "b:\t" << orb << std::endl;
	result = *ora+orb;
	std::cout << "a+b:\t" << result << std::endl;
	delete orb; orb = nullptr;
	delete result; result = nullptr;

	double *feanda = anda->foreach();
	double *feora = ora->foreach();
	std::cout << "FOREACH" << std::endl;
	std::cout << "anda: \t";
	for (int i = 0; i < anda->size(); ++i)
	{
		std::cout << feanda[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "ora: \t";
	for (int i = 0; i < ora->size(); ++i)
	{
		std::cout << feora[i] << " ";
	}
	std::cout << std::endl;

	delete anda; anda = nullptr;
	delete[] feanda; feanda = nullptr;
	delete ora; ora = nullptr;
	delete[] feora; feora = nullptr;

	return 0;
}
