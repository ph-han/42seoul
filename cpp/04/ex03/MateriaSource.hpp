#pragma once

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource{
	private:
		AMateria *_inventory[4];

	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource &copy);
		MateriaSource &operator=(const MateriaSource &copy);

		virtual void learnMateria(AMateria *);
		virtual AMateria *createMateria(std::string const &type);
};