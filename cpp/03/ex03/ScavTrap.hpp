#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &obj);
		ScavTrap(std::string name);

		void attack(const std::string &target);
		
		void guardGate();
};