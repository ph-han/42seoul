#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap Constructor called" << std::endl;
	_name = name;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;

	if (this == &obj)
		return *this;

	_name = obj.getName();
	_hitPoint = obj.getHitPoint();
	_energyPoint = obj.getEnergyPoint();
	_attackDamage = obj.getAttackDamage();

	return *this;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = copy;
}

void FragTrap::highFivesGuys(void)
{
	if (_hitPoint <= 0) {
		std::cout << "FragTrap " << _name << ": died" << std::endl;
	}
	std::cout << "high Fives Guys" << std::endl;
}