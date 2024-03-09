#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _requiredSignGrade;
		const int _requiredExecuteGrade;
	public:
		AForm();
		virtual ~AForm();
		const AForm& operator=(const AForm& copy);
		AForm(const AForm& copy);

		AForm(const std::string& name, const int signGrade, const int executeGrade);

		const std::string& getName(void) const;
		bool checkSigned(void) const;
		int getRequiredSignGrade(void) const;
		int getRequiredExecuteGrade(void) const;

		void beSigned(Bureaucrat bureaucrat);

		virtual void execute(Bureaucrat const & executor) const = 0;

		class NoSignException : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Not sign.";
			}
		};

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Your grade is too high.";
			}
		};

		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Your grade is too low.";
			}
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);