#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "Default constructor called\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called\n";
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {

}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called\n";
	_name = copy.getName();
	_hitPoint = copy.getHitPoint();
	_energyPoint = copy.getEnergyPoint();
	_attackDamage = copy.getAttackDamage();
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &obj)
		return *this;
	
	_name = obj.getName();
	_hitPoint = obj.getHitPoint();
	_energyPoint = obj.getEnergyPoint();
	_attackDamage = obj.getAttackDamage();

	return *this;
}

const std::string &ClapTrap::getName(void) const {
	return _name;
}

const int ClapTrap::getHitPoint(void) const {
	return _hitPoint;
}

const int ClapTrap::getEnergyPoint(void) const {
	return _energyPoint;
}
const int ClapTrap::getAttackDamage(void) const {
	return _attackDamage;
}

void ClapTrap::attack(const std::string &target) {
	std::cout << "ClapTrap " << _name 
		<< "attacks " << target 
		<< ", causing " << _attackDamage 
		<< "points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}