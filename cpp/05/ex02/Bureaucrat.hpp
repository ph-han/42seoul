#pragma once

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		const Bureaucrat& operator=(const Bureaucrat& copy);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat(std::string& name, int grade);


		const std::string& getName(void) const;
		int getGrade(void) const;

		void increment(void);
		void decrement(void);

		void signForm(AForm& form);
		void executeForm(AForm const& form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "GradeTooHighException (range: 150 ~ 1)";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "GradeTooLowException (range: 150 ~ 1)";
				}
		};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);