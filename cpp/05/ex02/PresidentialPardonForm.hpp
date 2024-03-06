#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	virtual ~PresidentialPardonForm();
	const PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	PresidentialPardonForm(const PresidentialPardonForm &copy);

	PresidentialPardonForm(const std::string &target);

	virtual void execute(Bureaucrat const &executor) const;
};