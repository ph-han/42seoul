#pragma once
#include "Weapon.h"

class HumanA {
private:
	std::string	_name;
	Weapon&		_weapon;

public:
	HumanA(std::string name, Weapon& _weapon);

	void attack(void);
};