#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern hcho2;
		std::string name = "phan";
		Bureaucrat phan(name, 1);
		
		AForm* shrubbery = hcho2.makeForm("shrubbery creation", "home");
		AForm* robotomy = hcho2.makeForm("robotomy request", "phan");
		AForm* pres = hcho2.makeForm("presidential pardon", "phan");

		phan.executeForm(*shrubbery);

		std::cout << *shrubbery << std::endl;
		std::cout << *robotomy << std::endl;
		std::cout << *pres << std::endl;

		std::cout << "\n------------------------\n"
				  << std::endl;

		phan.signForm(*shrubbery);
		phan.signForm(*robotomy);
		phan.signForm(*pres);

		std::cout << "\n------------------------\n"
				  << std::endl;
				  
		std::cout << *shrubbery << std::endl;
		std::cout << *robotomy << std::endl;
		std::cout << *pres << std::endl;

		phan.executeForm(*robotomy);
		phan.executeForm(*pres);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}