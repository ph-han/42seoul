#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &obj);
	FragTrap(std::string name);

	void highFivesGuys(void);

	void whoAmI(void);
};