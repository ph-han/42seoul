#include "Dog.hpp"
#include "Cat.hpp"

// void checkLeaks(void) {
// 	system("leaks animal");
// }

int main(void) {
	// atexit(checkLeaks);

	// AAnimal *error = new AAnimal();

	AAnimal *animalList[6];

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
	return 0;
}