#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("phan"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string& name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		const_cast<std::string&>(_name) = copy.getName();
		_grade = copy.getGrade();
	}
	
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	if (this == &copy)
		return ;

	const_cast<std::string &>(_name) = copy.getName();
	_grade = copy.getGrade();
}

const std::string& Bureaucrat::getName(void) const
{
	return _name;
}
int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::increment(void)
{
	if (--_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrement(void)
{
	if (++_grade > 150)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return out;
}
