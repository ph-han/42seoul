#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap() {
	ClapTrap::_name = this->_name + "_clap_name";
	_attackDamage = FragTrap::_attackDamage;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	ClapTrap::_name = this->_name + "_clap_name";
	_attackDamage = FragTrap::_attackDamage;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap() {
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;

	if (this == &obj)
		return *this;

	_name = obj.getName();
	_hitPoint = obj.getHitPoint();
	_energyPoint = obj.getEnergyPoint();
	_attackDamage = obj.getAttackDamage();

	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = copy;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "My name: " << _name << ", Clap name: " << ClapTrap::_name << std::endl;
}