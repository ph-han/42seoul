#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this == &obj)
		return *this;
	
	_name = obj.getName();
	_hitPoint = obj.getHitPoint();
	_energyPoint = obj.getEnergyPoint();
	_attackDamage = obj.getAttackDamage();

	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
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
		std::cout << "ClapTrap " << _name << " no enery or died" << std::endl;
		return ;
	}
	_energyPoint -= 1;
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
	std::cout << "ClapTrap " << _name << " take damage " << amount 
				<< "(Health: " << _hitPoint << ", Energy: " << _energyPoint << ")" << std::endl;
	if (_hitPoint < 0)
		_hitPoint = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoint <= 0 || _energyPoint <= 0) {
		std::cout << "ClapTrap " << _name << " no enery or died" << std::endl;
		return ;
	}
	_energyPoint -= 1;
	_hitPoint += amount;
	std::cout << "ClapTrap " << _name << " is repaired " << amount 
				<< " (Health: " << _hitPoint << ", Energy: " << _energyPoint << ")" << std::endl;
}
