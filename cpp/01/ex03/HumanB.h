#pragma once
#include "Weapon.h"

class HumanB {
private:
	std::string	_name;
	Weapon*		_weapon;

public:
	HumanB(std::string name);

	void attack(void);
	void setWeapon(Weapon weapon);
};