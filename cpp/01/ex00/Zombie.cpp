#include "Zombie.hpp"

Zombie::Zombie(): _name("None") {
	std::cout << _name << ": Constructor executed\n";
}

Zombie::Zombie(std::string name): _name(name) {
	std::cout << _name << ": Constructor executed\n";
}

Zombie::~Zombie() {
	std::cout << _name << ": Destructor executed\n";
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}