#include <iostream>
#include "iter.hpp"

int main()
{
	int a[7] = {1, 2, 3, 4, 5, 6, 7};
	char b[7] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	double c[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};

	std::cout << "=========== Array a ===========" << std::endl;
	std::cout << "before : ";
	for (int i = 0; i < 7; i++)
		std::cout << a[i] << " ";
	iter(a, 7, increase<int>);
	std::cout << "\nafter : ";
	for (int i = 0; i < 7; i++)
		std::cout << a[i] << " ";

	std::cout << std::endl;

	std::cout << "=========== Array b ===========" << std::endl;
	std::cout << "before : ";
	for (int i = 0; i < 7; i++)
		std::cout << b[i] << " ";
	iter(b, 7, increase<char>);
	std::cout << "\nafter : ";
	for (int i = 0; i < 7; i++)
		std::cout << b[i] << " ";

	std::cout << std::endl;

	std::cout << "=========== Array c ===========" << std::endl;
	std::cout << "before : ";
	for (int i = 0; i < 7; i++)
		std::cout << c[i] << " ";
	iter(c, 7, increase<double>);
	std::cout << "\nafter : ";
	for (int i = 0; i < 7; i++)
		std::cout << c[i] << " ";

	std::cout << std::endl;

	return 0;
}
