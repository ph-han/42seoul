#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return *this;
	
	_name = obj.getName();
	_hitPoint = obj.getHitPoint();
	_energyPoint = obj.getEnergyPoint();
	_attackDamage = obj.getAttackDamage();

	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}


const std::string &ClapTrap::getName(void) const {
	return _name;
}

int ClapTrap::getHitPoint(void) const {
	return _hitPoint;
}

int ClapTrap::getEnergyPoint(void) const {
	return _energyPoint;
}
int ClapTrap::getAttackDamage(void) const {
	return _attackDamage;
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoint <= 0 || _energyPoint <= 0) {
		std::cout << "ClapTrap " << _name << " no enery " << std::endl;
		return ;
	}
	_energyPoint -= 1;
	_attackDamage = 1;
	std::cout << "ClapTrap " << _name 
		<< " attacks " << target 
		<< ", causing " << _attackDamage 
		<< " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoint <= 0) {
		std::cout << "ClapTrap" << _name << " died " << std::endl;
		return ;
	}
	_hitPoint -= amount;
	std::cout << "ClapTrap " << _name << " take damage " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoint <= 0 || _energyPoint <= 0) {
		std::cout << "ClapTrap " << _name << " no enery " << std::endl;
		return ;
	}
	_energyPoint -= 1;
	_hitPoint += amount;
	std::cout << "ClapTrap " << _name << " is repaired " << amount << std::endl;
}