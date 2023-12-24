#include "HumanB.h"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {
}

void HumanB::attack(void) {
	std::cout << _name << " attacks with their " << _weapon->getType()<< "\n";
}

void HumanB::setWeapon(Weapon weapon) {
	_weapon = &weapon;
}