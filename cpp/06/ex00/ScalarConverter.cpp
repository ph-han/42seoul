#include "ScalarConverter.hpp"

int ScalarConverter::isValidInput(std::string& input)
{
	int pointCnt = 0;
	int charCnt = 0;
	size_t idx;
	bool isDoubleInfOrNan = input == "inf" | input == "+inf" || input == "-inf" || input == "nan";
	bool isFloatInfOrNan = input == "inff" | input == "+inff" || input == "-inff" || input == "nanf";

	if (isDoubleInfOrNan || isFloatInfOrNan)
		return INF_OR_NON;

	if (input.length() == 1)
		return SUCCESS;

	for (idx = 0; idx < input.length() - 1; idx++)
	{
		bool notPoint= input[idx] != '.';
		bool notNumber = input[idx] < '0' || input[idx] > '9';

		charCnt += (notPoint && notNumber);
		pointCnt += (notPoint == false);

		if (charCnt >= 1 || pointCnt >= 2)
			return ERROR;
	}

	if (input[idx] != 'f' && (input[idx] < '0' || input[idx] > '9'))
		return ERROR;

	return SUCCESS;
}

void ScalarConverter::convertChar(double inData, int flag)
{
	std::cout << "char: ";

	if (flag == INF_OR_NON || inData > CHAR_MAX || inData < CHAR_MIN)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	char data = static_cast<char>(inData);
	if (data < 32)
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}

	std::cout << "'" << data << "'" << std::endl;
}

void ScalarConverter::convertInt(double inData, int flag)
{
	std::cout << "int: ";

	if (flag == INF_OR_NON || inData > INT32_MAX || inData < INT32_MIN)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	int data = static_cast<int>(inData);
	std::cout << data << std::endl;
	
}
void ScalarConverter::convertFloat(double inData, int flag)
{
	std::cout << "float: ";

	if (flag == INF_OR_NON)
		std::cout << inData;
	else
	{
		float data = static_cast<float>(inData);
		float remainder = data - static_cast<int>(data);

		std::cout << data;
		if (remainder == 0.0f)
			std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

void ScalarConverter::convertDouble(double inData, int flag)
{
	(void)flag;
	std::cout << "double: ";

	double remainder = inData - static_cast<int>(inData);

	std::cout << inData;
	if (remainder == 0.0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(std::string input)
{
	int flag = isValidInput(input);
	if (flag == ERROR)
	{
		std::cout << "Your input data is wrong. Check please." << std::endl;
		return;
	}

	double inData;
	if (input.length() == 1 && (input[0] < '0' || input[0] > '9'))
		inData = static_cast<double>(input[0]);
	else
		inData = strtod(input.c_str(), NULL);
	
	convertChar(inData, flag);
	convertInt(inData, flag);
	convertFloat(inData, flag);
	convertDouble(inData, flag);
}
