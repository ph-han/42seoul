#include "Zombie.hpp"
#include <sstream>



Zombie *Zombie::zombieHorde(int N, std::string name) {
	Zombie *zList = new Zombie[N];
	std::stringstream ss;

	for (int i = 0; i < N; i++) {
		ss.str(std::string());
		ss << i;
		zList[i].setName(name + ss.str());
	}

	return zList;
}