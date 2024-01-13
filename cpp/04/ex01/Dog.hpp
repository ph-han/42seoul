#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
private:
	Brain *_brain;
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &obj);

	virtual void makeSound() const;
};