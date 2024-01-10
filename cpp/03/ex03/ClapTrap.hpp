#pragma once

#include <iostream>

class ClapTrap {
	protected:
		std::string _name;
		int			_hitPoint;
		int			_energyPoint;
		int			_attackDamage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap &obj);
		ClapTrap(std::string name);

		const std::string&	getName(void) const;
		int 				getHitPoint(void) const;
		int 				getEnergyPoint(void) const;
		int					getAttackDamage(void) const;

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void whoAmI(void);
};