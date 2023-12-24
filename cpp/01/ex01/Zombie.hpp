#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string _name;

	void setName(std::string name);
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	Zombie *zombieHorde(int N, std::string name);
};

#endif