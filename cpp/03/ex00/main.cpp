#include "ClapTrap.hpp"

int main(void) {
	ClapTrap a("a");
	ClapTrap b("b");

	a.attack("b");
	b.takeDamage(3);
	b.beRepaired(3);
	a.attack("b");
	b.takeDamage(10);
	b.beRepaired(10);
	for (int i = 0; i < 10; i++)
		a.attack("b");
	a.attack("b");
}