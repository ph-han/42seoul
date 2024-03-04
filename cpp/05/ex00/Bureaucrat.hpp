#pragma once

#include <iostream>

class Bureaucrat {
	private:
		const std::string _name;
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		const Bureaucrat& operator=(const Bureaucrat& copy);
		Bureaucrat(const Bureaucrat& copy);

		const std::string& getName(void) const;
		int getGrade(void) const;

		void increment(void);
		void decrement(void);                                     
};