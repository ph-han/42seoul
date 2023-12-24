#include "Zombie.hpp"


int main(void) {
	Zombie zombie1("phan");
	Zombie zombie2;

	zombie1.announce();
	randomChump("hcho2");
	Zombie *sz = newZombie("sanglee2");
	sz->announce();
	delete sz;
}

