#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name) {
	
}

Zombie::~Zombie() {
	std::cout << "\n" << _name << ": Destructor executed\n";
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}