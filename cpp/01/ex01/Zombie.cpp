#include "Zombie.hpp"

Zombie::Zombie() : _name("None") {
	std::cout << "\n" << _name << ": Constructor executed\n";
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "\n" << _name << ": Constructor executed\n";
}

Zombie::~Zombie() {
	std::cout << "\n" << _name << ": Destructor executed\n";
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}