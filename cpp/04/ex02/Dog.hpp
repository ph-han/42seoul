#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal {
private:
	Brain *_brain;
public:
	Dog();
	~Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &obj);

	void makeSound() const;
};