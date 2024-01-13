#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure() {
	// std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &copy) {
	// std::cout << "Cure copy constructor called" << std::endl;
	*this = copy;
}

Cure &Cure::operator=(const Cure &copy) {
	// std::cout << "Cure copy operator called" << std::endl;

	if (this != &copy)
	{
		_type = copy.getType();
	}

	return *this;
}

AMateria *Cure::clone() const {
	Cure *cloneCure = new Cure();

	return cloneCure;
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}