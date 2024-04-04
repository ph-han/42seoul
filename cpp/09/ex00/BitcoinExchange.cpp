#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
	std::ifstream infs("data.csv");

	if (infs.is_open() == false)
	{
		std::cout << "File open error" << std::endl;
		return ;
	}

	std::string line;
	while (getline(infs, line))
	{
		size_t delimeterPos = line.find(',');
		std::string date = line.substr(0, delimeterPos);
		std::string value = line.substr(delimeterPos + 1);
		size_t hashDate = makeHash(date);

		if (hashDate != size_t(-1))
			_datasets[hashDate] = stof(value, false);
	}
	infs.close();
}

BitcoinExchange::~BitcoinExchange() {}

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
	{
		_datasets = copy._datasets;
	}

	return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	if (this != &copy)
	{
		_datasets = copy._datasets;
	}
}

void BitcoinExchange::exchange(char* filename)
{
	std::ifstream infs(filename);

	if (infs.is_open() == false)
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	while (getline(infs, line))
	{
		size_t delimeterPos = line.find('|');
		std::string dateStr = line.substr(0, delimeterPos);
		std::string valueStr = line.substr(delimeterPos + 1);
		trim(dateStr);
		trim(valueStr);
		if (dateStr == "date" && valueStr == "value")
			continue;
		size_t date = makeHash(dateStr);
		float value = stof(valueStr, true);
		if (date == size_t(-1))
		{
			std::cout << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		if (value == -1.0f)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value == -2.0f)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		if (value == -3.0f)
		{
			std::cout << "Error: input file format error." << std::endl;
			continue;
		}
		float closestDateVal = _datasets[findClosestDate(date)];
		std::cout << dateStr << " => " << valueStr << " = " << closestDateVal * value << std::endl;

	}
	infs.close();
}

size_t BitcoinExchange::makeHash(const std::string &date)
{
	const size_t hashMultiplier = 31;
	size_t hashValue = 0;

	std::istringstream iss(date);
	int year, month, day;
	char dash;

	iss >> year >> dash >> month >> dash >> day;

	if (year < 0 || (month > 12 || month < 1) || (day < 1 || day > 31))
		return -1;

	if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return -1;

	hashValue += year * hashMultiplier * hashMultiplier;
    hashValue += month * hashMultiplier;
    hashValue += day;

	return hashValue;
}

float BitcoinExchange::stof(const std::string& val, bool flag)
{
	std::istringstream iss(val);
	float retValue = 0.0f;

	iss >> retValue;

	if (flag == false)
		return retValue;

	if (iss.fail())
		return -3.0f;
	if (retValue > 100.0f)
		return -2.0f;
	if (retValue < 0.0f)
		return -1.0f;
	return retValue;
}

size_t BitcoinExchange::findClosestDate(size_t date)
{
	std::map<size_t, float>::iterator it = _datasets.begin();
	std::map<size_t, float>::iterator ite = _datasets.end();
	size_t shortestSpan = it->first > date ? it->first - date : date - it->first;
	size_t closestDate = it->first;
	while (it != ite)
	{
		size_t tmp = it->first > date ? it->first - date : date - it->first;
		if (shortestSpan > tmp)
		{
			shortestSpan = tmp;
			closestDate = it->first;
		}
		++it;
	}
	return closestDate;
}

void BitcoinExchange::trim(std::string& str)
{
	str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
}
