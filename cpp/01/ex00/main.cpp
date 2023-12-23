#include "Zombie.hpp"


int main(void) {
	Zombie zombie1("phan");
	Zombie zombie2;

	zombie1.announce();
	zombie1.randomChump("hcho2");
	Zombie *sz = zombie1.newZombie("sanglee2");
	sz->announce();
}