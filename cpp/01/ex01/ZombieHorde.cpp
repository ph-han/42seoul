#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name) {
	Zombie zList[N];

	for (int i = 0; i < N; i++) {
		zList[i] = Zombie(name);
	}

	return zList;
}