#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &obj)
{
	std::cout << "Dog copy assignment operator called\n";
	if (this == &obj)
		return *this;
	_type = obj.getType();
	if (_brain)
		delete _brain;
	_brain = new Brain();
	return *this;
}

Dog::Dog(const Dog &copy): _brain(NULL)
{
	std::cout << "Dog copy constructor called\n";
	*this = copy;
}

void Dog::makeSound() const
{
	std::cout << "Woof~" << std::endl;
}