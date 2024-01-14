#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
	Animal *animalList[6];

	for(int i = 0; i < 3; i++)
		animalList[i] = new Dog();

	for(int i = 3; i < 6; i++)
		animalList[i] = new Cat();

	for (int i = 0; i < 6; i++) {
		std::cout << animalList[i]->getType() << " : ";
		animalList[i]->makeSound();
	}

	for (int i = 0; i < 6; i++)
		delete animalList[i];

	Dog dog1;
	Dog dog2(dog1);
	
	dog2.makeSound();
	std::cout << &dog1 << std::endl;
	std::cout << &dog2 << std::endl;

	return 0;
}