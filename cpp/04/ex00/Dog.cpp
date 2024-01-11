#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << "Dog copy assignment operator called\n";
	if (this == &obj)
		return *this;
	_type = obj.getType();
	return *this;
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called\n";
	*this = copy;
}

void Dog::makeSound() const
{
	std::cout << "Woof~" << std::endl;
}