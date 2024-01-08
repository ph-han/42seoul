#include "ClapTrap.hpp"

int main(void) {
	ClapTrap a("a");
	ClapTrap b("b");

	a.attack("b");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(a.getAttackDamage());
	for (int i = 0; i < 10; i++)
		a.attack("b");
	a.attack("b");
}