#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "origin string pointer: " << &str << "\n";
	std::cout << "stringPTR : " << stringPTR << "\n";
	std::cout << "stringREF : " << &stringREF << "\n";
	std::cout << "\n";
	std::cout << "origin string value: " << str << "\n";
	std::cout << "stringPTR : " << *stringPTR << "\n";
	std::cout << "stringREF : " << stringREF << "\n";

	return 0;
}