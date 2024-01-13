#pragma once

#include <iostream>

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal &operator=(const Animal &obj);

		const std::string &getType() const;

		virtual void makeSound() const;
};