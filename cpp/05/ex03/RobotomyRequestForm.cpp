#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("home") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), _target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getRequiredExecuteGrade())
		throw GradeTooLowException();
	
	if (std::rand() % 2)
		std::cout << _target << " success" << std::endl;
	else
		std::cout << _target << " fail" << std::endl;
}