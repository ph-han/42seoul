#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* makeShrubberyCreationForm(const std::string &target);
		AForm* makeRobotomyRequestForm(const std::string &target);
		AForm* makePresidentialPardonForm(const std::string &target);

	public : 
		Intern();
		~Intern();
		const Intern& operator=(const Intern& copy);
		Intern(const Intern& copy);

		AForm* makeForm(std::string name, std::string target);

		class WrongFormName : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Wrong form name check your input.";
				}
		};
};
