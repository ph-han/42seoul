#pragma once

#include "Animal.hpp"

class Dog: public Animal {
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &obj);

	virtual void makeSound() const;
};