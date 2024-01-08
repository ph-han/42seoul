#include "ScavTrap.hpp"

int main(void) {
	ClapTrap a("a");
	ClapTrap b("b");

	a.attack("b");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	for (int i = 0; i < 10; i++)
		a.attack("b");

	ScavTrap c("c");
	ScavTrap d("d");

	c.attack("b");
	d.takeDamage(c.getAttackDamage());
	d.beRepaired(5);
	for (int i = 0; i < 5; i++)
		c.attack("b");
}