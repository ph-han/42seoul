#pragma once
#include <iostream>
#include <string>

class Sed {
	private:
		std::string _originWord;
		std::string _replaceWord;

	public:
		Sed(std::string originWord, std::string replaceWord);

		void replace(std::string &line);
};