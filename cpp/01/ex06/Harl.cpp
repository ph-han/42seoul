#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
}

void Harl::info(void) {
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
				<< "years whereas you started working here since last month.\n\n";
}

void Harl::error(void) {
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int iter;

	for (iter = 0; iter < 4; iter++) {
		if (levels[iter] == level)
			break;
	}
	
	switch (iter) {
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
}