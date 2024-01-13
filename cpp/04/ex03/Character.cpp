#include "Character.hpp"

Character::Character() : _name("Default") {
	// std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name){
	// std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character() {
	// std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

Character::Character(const Character &copy) {
	// std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = copy;
}

Character &Character::operator=(const Character &copy) {
	// std::cout << "Character copy operator called" << std::endl;

	if (this != &copy) {
		_name = copy._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i] != NULL)
				delete _inventory[i];
			_inventory[i] = copy._inventory[i]->clone();
		}
	}

	return *this;
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 4 || idx < 0) {
		std::cout << "[Index Error] Check yout input!" << std::endl;
		return ;
	}

	if (_inventory[idx] == NULL) {
		std::cout << "Inventory [" << idx << "] is empty!" << std::endl;
		return ;
	}

	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 4 || idx < 0) {
		std::cout << "[Index Error] Check yout input!" << std::endl;
		return;
	}
	if (_inventory[idx] == NULL) {
		std::cout << "Inventory [" << idx << "] is empty!" << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}

AMateria *Character::getInven(const int idx) const {
	if (idx >= 4 || idx < 0) {
		std::cout << "[Index Error] Check yout input!" << std::endl;
		return NULL;
	}
	return _inventory[idx];
}