#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>


class BitcoinExchange
{
	private:
		std::map<size_t, float> _datasets;

		size_t makeHash(const std::string& date);
		float stof(const std::string& val, bool flag);

		size_t findClosestDate(size_t date);
		void trim(std::string& str);
		bool isLeapYear(int year);
	public:
		BitcoinExchange();
		~BitcoinExchange();
		const BitcoinExchange& operator= (const BitcoinExchange& copy);
		BitcoinExchange(const BitcoinExchange& copy);

		void exchange(char* filename);
};
