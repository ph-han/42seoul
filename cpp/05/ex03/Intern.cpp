#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

const Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*newFormList[])(const std::string& target) = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (formList[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*newFormList[i])(target);
		}
	}
	throw WrongFormName();
	return NULL;
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}
