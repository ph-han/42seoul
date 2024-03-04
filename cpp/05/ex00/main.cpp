#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		// Bureaucrat a;
		// std::cout << a << std::endl;
		// a.decrement();
		// std::cout << a << std::endl;
		// a.increment();
		// std::cout << a << std::endl;
		// a.increment();
		// std::cout << a << std::endl;

		std::string name = "phan";
		Bureaucrat b(name, 150);
		std::cout << b << std::endl;
		b.decrement();

		// Bureaucrat c(name, 160);
		// Bureaucrat d(name, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}