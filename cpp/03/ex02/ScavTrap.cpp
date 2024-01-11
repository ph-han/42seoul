#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap Constructor called" << std::endl;
	_name = name;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj) {
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;

	if (this == &obj)
		return *this;

	_name = obj.getName();
	_hitPoint = obj.getHitPoint();
	_energyPoint = obj.getEnergyPoint();
	_attackDamage = obj.getAttackDamage();

	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = copy;
}

void ScavTrap::guardGate() {
	if (_hitPoint <= 0) {
		std::cout << "ScavTrap " << _name << ": died" << std::endl;
		return ;
	}
	std::cout << "Gate keeper mode start" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hitPoint <= 0 || _energyPoint <= 0) {
		std::cout << "ScavTrap " << _name << " no enery or died" << std::endl;
		return;
	}
	_energyPoint -= 1;
	std::cout << "ScavTrap " << _name
			  << " attacks " << target
			  << ", causing " << _attackDamage
			  << " points of damage !" 
			  << " (Health: " << _hitPoint << ", Energy: " << _energyPoint << ")" << std::endl;
}