#include "ScavTrap.hpp"

int main(void) {
	ScavTrap a("a");
	ScavTrap b("b");

	a.attack("b");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	for (int i = 0; i < 10; i++)
		a.attack("b");
}