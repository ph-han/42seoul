#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _requiredSignGrade;
		const int _requiredExecuteGrade;
	public:
		Form();
		~Form();
		const Form& operator=(const Form& copy);
		Form(const Form& copy);

		const std::string& getName(void) const;
		bool checkSigned(void) const;
		int getRequiredSignGrade(void) const;
		int getRequiredExecuteGrade(void) const;

		void beSigned(Bureaucrat bureaucrat);

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

std::ostream& operator<<(std::ostream& out, const Form& obj);