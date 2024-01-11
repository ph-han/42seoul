#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat &Cat::operator=(const Cat &obj)
{
	std::cout << "Cat copy assignment operator called\n";
	if (this == &obj)
		return *this;
	_type = obj.getType();
	return *this;
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called\n";
	*this = copy;
}

void Cat::makeSound() const
{
	std::cout << "Meow~" << std::endl;
}