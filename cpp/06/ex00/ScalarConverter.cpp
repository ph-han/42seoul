#include "ScalarConverter.hpp"

int ScalarConverter::isValidInput(std::string& input)
{
	int pointCnt = 0;
	int charCnt = 0;
	size_t idx;
	bool isDoubleInfOrNan = input == "inf" | input == "+inf" || input == "-inf" || input == "nan";
	bool isFloatInfOrNan = input == "inff" | input == "+inff" || input == "-inff" || input == "nanf";

	if (input == ".f")
		return ERROR;
		
	if (isDoubleInfOrNan || isFloatInfOrNan)
		return INF_OR_NON;

	if (input.length() == 1 && (input[0] < '0' || input[0] > '9'))
		return CHAR;

	if (input.length() == 1 && (input[0] >= '0' && input[0] <= '9'))
		return INT;

	for (idx = 0; idx < input.length(); idx++)
	{
		bool notPoint = input[idx] != '.';
		bool notNumber = input[idx] < '0' || input[idx] > '9';

		charCnt += (notPoint && notNumber);
		pointCnt += (notPoint == false);

		if (charCnt >= 2 || pointCnt >= 2)
			return ERROR;
	}

	bool notFloatSymbol = (input[idx - 1] != 'f' && input[idx - 1] != '.' && (input[idx - 1] < '0' || input[idx - 1] > '9'));

	if (notFloatSymbol || (pointCnt == 0 && input[idx - 1] == 'f'))
		return ERROR;

	if (pointCnt == 1 && input[idx] == 'f')
		return FLOAT;

	if (pointCnt == 1)
		return DOUBLE;
	
	return INT;
}

void ScalarConverter::convertCharToOther(char inData, int flag)
{
	int convertInt = static_cast<int>(inData);
	float convertFloat = static_cast<float>(inData);
	double convertDouble = static_cast<double>(inData);

	if (flag == INF_OR_NON)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossibble" << std::endl;
		std::cout << "float: impossibble" << std::endl;
		std::cout << "double: impossibble" << std::endl;
		return ;
	}

	if (inData < 32 || inData == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << inData << "'" << std::endl;

	std::cout << "int: " << convertInt << std::endl;
	std::cout << "float: " << convertFloat << ".0f" << std::endl;
	std::cout << "double: " << convertDouble << ".0" <<  std::endl;
}

void ScalarConverter::convertIntToOther(int inData, int flag)
{
	char convertChar = static_cast<char>(inData);
	float convertFloat = static_cast<float>(inData);
	double convertDouble = static_cast<double>(inData);

	if (flag == INF_OR_NON)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossibble" << std::endl;
		std::cout << "float: impossibble" << std::endl;
		std::cout << "double: impossibble" << std::endl;
		return;
	}

	if (inData < 32 || inData == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if(inData > CHAR_MAX || inData < CHAR_MIN)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << convertChar << "'" << std::endl;

	std::cout << "int: " << inData << std::endl;
	std::cout << "float: " << convertFloat << ".0f" << std::endl;
	std::cout << "double: " << convertDouble << ".0" << std::endl;
}
void ScalarConverter::convertFloatToOther(float inData, int flag)
{
	char convertChar = static_cast<char>(inData);
	int convertInt  = static_cast<int>(inData);
	double convertDouble = static_cast<double>(inData);

	if (flag == INF_OR_NON || inData > CHAR_MAX || inData < CHAR_MIN)
		std::cout << "char: impossible" << std::endl;
	else if (inData < 32 || inData == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << convertChar << "'" << std::endl;

	if (flag == INF_OR_NON || inData > INT32_MAX || inData < INT32_MIN)
		std::cout << "int: impossibble" << std::endl;
	else
		std::cout << "int: " << convertInt << std::endl;

	std::cout << "float: " << inData;
	if ((inData - convertInt) == 0.0f)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << convertDouble;
	if ((convertDouble - convertInt) == 0.0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertDoubleToOther(double inData, int flag)
{
	char convertChar = static_cast<char>(inData);
	int convertInt = static_cast<int>(inData);
	float convertFloat = static_cast<float>(inData);

	if (flag == INF_OR_NON || inData > CHAR_MAX || inData < CHAR_MIN)
		std::cout << "char: impossible" << std::endl;
	else if (inData < 32 || inData == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << convertChar << "'" << std::endl;

	if (flag == INF_OR_NON || inData > INT32_MAX || inData < INT32_MIN)
		std::cout << "int: impossibble" << std::endl;
	else
		std::cout << "int: " << convertInt << std::endl;

	std::cout << "float: " << convertFloat;
	if ((convertFloat - convertInt) == 0.0f)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << inData;
	if ((inData - convertInt) == 0.0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertInfOrNon(double infOrNon)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << infOrNon << "f" << std::endl;
	std::cout << "double: " << infOrNon << std::endl;
}

void ScalarConverter::convert(std::string input)
{
	int flag = isValidInput(input);
	if (flag == ERROR)
	{
		std::cout << "Your input data is wrong. Check please." << std::endl;
		return;
	}
	
	double inData = strtod(input.c_str(), NULL);

	switch (flag)
	{
	case CHAR:
		{
			if (inData > CHAR_MAX || inData < CHAR_MIN)
				flag = INF_OR_NON;
			char dataChar = input[0];
			convertCharToOther(dataChar, flag);
		}
		break;
	case INT:
		{
			if (inData > INT32_MAX || inData < INT32_MIN)
				flag = INF_OR_NON;
			int dataInt = std::atoi(input.c_str());
			convertIntToOther(dataInt, flag);
		}
		break;
	case FLOAT:
		{
			float dataFloat = std::strtof(input.c_str(), NULL);
			if (dataFloat > std::numeric_limits<float>::max() || dataFloat > -std::numeric_limits<float>::max())
				flag = INF_OR_NON;
			convertFloatToOther(dataFloat, flag);
		}
		break;
	case DOUBLE:
		convertDoubleToOther(inData, flag);
		break;
	default:
		convertInfOrNon(inData);
		break;
	}
}
