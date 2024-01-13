#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal {
private:
	Brain *_brain;
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &obj);

	virtual void makeSound() const;
};