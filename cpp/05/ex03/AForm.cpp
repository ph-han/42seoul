#include "AForm.hpp"

AForm::AForm() : _name("phan"), _isSigned(false), _requiredSignGrade(50), _requiredExecuteGrade(100) {}

AForm::~AForm() {}

const AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
	{
		const_cast<std::string&>(_name) = copy.getName();
		_isSigned = copy.checkSigned();
		const_cast<int&>(_requiredSignGrade) = copy.getRequiredSignGrade();
		const_cast<int&>(_requiredExecuteGrade) = copy.getRequiredExecuteGrade();
	}

	return *this;
}

AForm::AForm(const AForm& copy) : _requiredSignGrade(0), _requiredExecuteGrade(0)
{
	if (this == &copy)
		return ;

	const_cast<std::string&>(_name) = copy.getName();
	_isSigned = copy.checkSigned();
	const_cast<int&>(_requiredSignGrade) = copy.getRequiredSignGrade();
	const_cast<int&>(_requiredExecuteGrade) = copy.getRequiredExecuteGrade();
}

AForm::AForm(const std::string& name, const int signGrade, const int executeGrade) : _name(name), _isSigned(false), _requiredSignGrade(signGrade), _requiredExecuteGrade(executeGrade) {}

const std::string& AForm::getName(void) const
{
	return _name;
}

bool AForm::checkSigned(void) const
{
	return _isSigned;
}

int AForm::getRequiredSignGrade(void) const
{
	return _requiredSignGrade;
}

int AForm::getRequiredExecuteGrade(void) const
{
	return _requiredExecuteGrade;
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > _requiredSignGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << obj.getName() << ", form required sign grade " << obj.getRequiredSignGrade() << ", form required execute grade " << obj.getRequiredExecuteGrade() << " [ sign : " << obj.checkSigned() << " ].";
	return out;
}