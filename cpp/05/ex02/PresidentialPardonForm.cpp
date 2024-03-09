#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("home") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential", 25, 5), _target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > getRequiredExecuteGrade())
		throw GradeTooLowException();

	if (checkSigned() == false)
		throw NoSignException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
