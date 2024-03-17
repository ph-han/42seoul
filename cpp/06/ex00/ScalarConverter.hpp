#pragma once

#include <iostream>
#include <limits>


#define INF_OR_NON	0
#define ERROR		1
#define CHAR		2
#define INT			3
#define FLOAT		4
#define DOUBLE		5

class ScalarConverter
{
	private:
		ScalarConverter();
		const ScalarConverter& operator=(const ScalarConverter& copy);
		ScalarConverter(const ScalarConverter& copy);

		static int isValidInput(std::string& input);

		static void convertCharToOther(char inData, int flag);
		static void convertIntToOther(int inData, int flag);
		static void convertFloatToOther(float inData, int flag);
		static void convertDoubleToOther(double inData, int flag);
		static void convertInfOrNon(double infOrNon);

	public:
		~ScalarConverter();

		static void convert(std::string input);    
};