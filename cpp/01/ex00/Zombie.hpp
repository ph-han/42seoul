#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	Zombie* newZombie( std::string name );
	void	announce( void );
	void	randomChump( std::string name );
};

#endif