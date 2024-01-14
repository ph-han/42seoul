#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// void checkLeaks(void) {
// 	system("leaks imple");
// }

int main()
{
	// atexit(checkLeaks);
	AMateria *floor[100];

	for (int i = 0; i < 100; i++)
			floor[i] = NULL;

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n== equip(), use() Example ==" << std::endl;
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n== unequip() Example ==" << std::endl;
	Character *me2 = new Character("me");
	AMateria *tmp2;
	tmp2 = src->createMateria("ice");
	me2->equip(tmp2);
	tmp2 = src->createMateria("cure");
	me2->equip(tmp2);

	floor[0] = me2->getInven(0);
	me2->unequip(0);
	me2->use(0, *bob);

	floor[1] = me2->getInven(1);
	me2->unequip(1);
	me2->use(1, *bob);

	std::cout << "\n== use() Error Case ==" << std::endl;
	me->use(-1, *bob);
	me->use(5, *bob);
	me->use(3, *bob);

	std::cout << "\n== unequip() Error Case ==" << std::endl;
	me->unequip(-1);
	me->unequip(5);
	me->use(3, *bob);

	for (int i = 0; i < 100; i++)
		if (floor[i])
			delete(floor[i]);
	delete bob;
	delete me;
	delete me2;
	delete src;
	return 0;
}