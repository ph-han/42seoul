#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice() {
	// std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &copy) {
	// std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
}

Ice &Ice::operator= (const Ice &copy) {
	// std::cout << "Ice copy operator called" << std::endl;

	if (this != &copy) {
		_type = copy.getType();
	}

	return *this;
}

AMateria *Ice::clone() const {
	Ice *cloneIce = new Ice();

	return cloneIce;
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " * " << std::endl;
}