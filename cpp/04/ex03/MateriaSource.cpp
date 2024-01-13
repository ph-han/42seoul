#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	// std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource() {
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	// std::cout << "MateriaSource copy operator called" << std::endl;

	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] != NULL)
				delete _inventory[i];
			_inventory[i] = copy._inventory[i]->clone();
		}
	}

	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	return NULL;
}
