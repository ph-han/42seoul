#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		virtual ~ShrubberyCreationForm();
		const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);

		ShrubberyCreationForm(const std::string& target);

		virtual void execute(Bureaucrat const & executor) const;
};