#include "Animal.hpp"

Animal::Animal() {
	_type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj) {
	std::cout << "Animal copy assignment operator called\n";
	if (this == &obj)
		return *this;
	_type = obj.getType();
	return *this;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy constructor called\n";
	*this = copy;
}

const std::string &Animal::getType() const {
	return _type;
}

void Animal::makeSound() const{
	std::cout << "Animal Sound!" << std::endl;
}