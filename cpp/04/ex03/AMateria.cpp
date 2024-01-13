#include "AMateria.hpp"

AMateria::AMateria() {
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy) {
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = copy;
}

AMateria::~AMateria() {
	// std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copy) {
	// std::cout << "AMateria copy operator called" << std::endl;
	if (this != &copy) {
		_type = copy.getType();
	}

	return *this;
}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	if (this->getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " * " << std::endl;
	else if (this->getType() == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
