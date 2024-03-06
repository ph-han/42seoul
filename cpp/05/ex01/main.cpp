#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		std::string name = "phan";
		Bureaucrat phan(name, 13);

		name = "hyuim";
		Bureaucrat hyuim(name, 150);

		Form f1;

		phan.signForm(f1);
		hyuim.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}