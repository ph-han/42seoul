#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery", 145, 137), _target("home") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shrubbery", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > getRequiredExecuteGrade())
		throw GradeTooLowException();
	std::string filename = _target + "_shrubbery";
	std::ofstream writeFile(filename);
	if (writeFile.is_open())
	{
		writeFile << "            .        +          .      .          .\n" 
				<< "						 ._..,\n"
				<< "			;-._,-.____        ,-----.__\n"
 				<< "((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
				<< "  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
				<< "                      ,    `./  \\:. `.   )==-'  .\n"
				<< "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
				<< ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
				<< "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
				<< "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
				<< "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
				<< "              \\:  `  X` _| _,\\/'   .-'\n"
				<< ".               \":._:`\\____  /:'  /      .           .\n"
				<< "                    \\::.  :\\/:'  /              +\n"
				<< "   .                 `.:.  /:'  }      .\n"
				<< "           .           ):_(:;   \\           .\n"
				<< "                      /:. _/ ,  |\n"
				<< "                   . (|::.     ,`                  .\n"
				<< "     .                |::.    {\\\n"
				<< "                      |::.\\  \\ `.\n"
				<< "                      |:::(\\    |\n"
				<< "              O       |:::/{ }  |                  (o\n"
				<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
				<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"
				<< "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~";
		writeFile.close();
	}
}

