#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat copy assignment operator called\n";
	if (this == &obj)
		return *this;
	_type = obj.getType();
	return *this;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor called\n";
	*this = copy;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow~" << std::endl;
}