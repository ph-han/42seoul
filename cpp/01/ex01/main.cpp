#include "Zombie.hpp"

int main(void) {
	Zombie zombie("leader");
	Zombie *zList;

	zList = zombie.zombieHorde(5, "zombie");
	for (int i = 0; i < 5; i++)
		zList[i].announce();
	delete [] zList;
	return (0);
}