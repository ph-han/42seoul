#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &obj);

	virtual void makeSound() const;
};