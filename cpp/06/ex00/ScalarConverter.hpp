#pragma once

#include <iostream>
#include <limits>


#define INF_OR_NON	0
#define ERROR		1
#define SUCCESS		2

class ScalarConverter
{
	private:
		ScalarConverter();
		const ScalarConverter& operator=(const ScalarConverter& copy);
		ScalarConverter(const ScalarConverter& copy);

		static int isValidInput(std::string& input);

		static void convertChar(double inData, int flag);
		static void convertInt(double inData, int flag);
		static void convertFloat(double inData, int flag);
		static void convertDouble(double inData, int flag);

	public:
		~ScalarConverter();

		static void convert(std::string input);    
};