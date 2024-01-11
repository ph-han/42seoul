#include "ScavTrap.hpp"

int main(void) {
	ScavTrap c("c");
	ScavTrap d("d");

	c.attack("b");
	d.takeDamage(c.getAttackDamage());
	d.beRepaired(5);
	for (int i = 0; i < 5; i++)
		c.attack("b");
}