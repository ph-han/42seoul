#include "DiamondTrap.hpp"

int main(void) {
	// ClapTrap a("a");
	// ClapTrap b("b");

	// a.attack("b");
	// b.takeDamage(a.getAttackDamage());
	// b.beRepaired(a.getAttackDamage());
	// for (int i = 0; i < 10; i++)
	// 	a.attack("b");

	// ScavTrap c("c");
	// ScavTrap d("d");

	// c.attack("d");
	// d.takeDamage(c.getAttackDamage());
	// d.beRepaired(c.getAttackDamage());
	// for (int i = 0; i < 10; i++)
	// 	c.attack("d");
	// c.guardGate();
	// d.guardGate();

	// FragTrap e("e");
	// FragTrap f("f");
	// e.attack("f");
	// f.takeDamage(e.getAttackDamage());
	// f.beRepaired(e.getAttackDamage());
	// for (int i = 0; i < 10; i++)
	// 	e.attack("f");
	// e.highFivesGuys();
	// f.highFivesGuys();

	DiamondTrap g("g");
	g.attack("f");
	g.takeDamage(g.getAttackDamage());
	g.beRepaired(g.getAttackDamage());
	for (int i = 0; i < 10; i++)
		g.attack("f");
	g.highFivesGuys();
	g.guardGate();
	g.whoAmI();
}