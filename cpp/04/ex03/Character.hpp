#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria *_inventory[4];
	public:
		Character();
		virtual ~Character();
		Character(const Character &copy);
		Character &operator=(const Character &copy);

		Character(std::string name);

		virtual std::string const &getName() const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);

		AMateria *getInven(const int idx) const;
};