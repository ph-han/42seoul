#pragma once

#include <iostream>

class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal &operator=(const AAnimal &obj);

		const std::string &getType() const;

		virtual void makeSound() const = 0;
};