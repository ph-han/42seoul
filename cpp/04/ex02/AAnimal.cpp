#include "AAnimal.hpp"

AAnimal::AAnimal() {
	_type = "AAnimal";
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &obj) {
	std::cout << "AAnimal copy assignment operator called\n";
	if (this == &obj)
		return *this;
	_type = obj.getType();
	return *this;
}

AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << "AAnimal copy constructor called\n";
	*this = copy;
}

const std::string &AAnimal::getType() const {
	return _type;
}
