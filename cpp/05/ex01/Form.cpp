#include "Form.hpp"

Form::Form() : _name("phan"), _isSigned(false), _requiredSignGrade(50), _requiredExecuteGrade(100) {}

Form::~Form() {}

const Form& Form::operator=(const Form& copy)
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

Form::Form(const Form& copy) : _requiredSignGrade(0), _requiredExecuteGrade(0)
{
	if (this == &copy)
		return ;

	const_cast<std::string&>(_name) = copy.getName();
	_isSigned = copy.checkSigned();
	const_cast<int&>(_requiredSignGrade) = copy.getRequiredSignGrade();
	const_cast<int&>(_requiredExecuteGrade) = copy.getRequiredExecuteGrade();
}

const std::string &Form::getName(void) const
{
	return _name;
}

bool Form::checkSigned(void) const
{
	return _isSigned;
}

int Form::getRequiredSignGrade(void) const
{
	return _requiredSignGrade;
}

int Form::getRequiredExecuteGrade(void) const
{
	return _requiredExecuteGrade;
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > _requiredSignGrade)
		throw GradeTooLowException();
	_isSigned = true;
}
