#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		std::string name = "phan";
		Bureaucrat phan(name, 1);

		name = "hyuim";
		Bureaucrat hyuim(name, 150);

		name = "jonhan";
		Bureaucrat jonhan(name, 140);

		ShrubberyCreationForm shrubbery("home");
		RobotomyRequestForm robotomy("teahkwon");
		PresidentialPardonForm pres("hcho2");

		phan.executeForm(shrubbery);

		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pres << std::endl;

		std::cout << "\n------------------------\n"
				  << std::endl;

		phan.signForm(shrubbery);
		phan.signForm(robotomy);
		phan.signForm(pres);

		std::cout << "\n------------------------\n"
				  << std::endl;
				  
		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pres << std::endl;

		phan.executeForm(shrubbery);
		phan.executeForm(robotomy);

		std::cout << "\n------------------------\n"
				  << std::endl;

		jonhan.signForm(shrubbery);
		jonhan.signForm(robotomy);
		jonhan.signForm(pres);
		jonhan.executeForm(shrubbery);

		std::cout << "\n------------------------\n"
				  << std::endl;

		hyuim.signForm(shrubbery);
		hyuim.signForm(robotomy);
		hyuim.signForm(pres);
		hyuim.executeForm(shrubbery);
		hyuim.executeForm(robotomy);
		hyuim.executeForm(pres);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}