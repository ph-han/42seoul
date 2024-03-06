#pragma once

#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm();
	virtual ~RobotomyRequestForm();
	const RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	RobotomyRequestForm(const RobotomyRequestForm &copy);

	RobotomyRequestForm(const std::string &target);

	virtual void execute(Bureaucrat const &executor) const;
};