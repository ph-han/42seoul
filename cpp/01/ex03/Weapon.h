#pragma once
#include <iostream>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon(std::string type);

		const std::string& getType(void) const;
		void setType(std::string type);
};