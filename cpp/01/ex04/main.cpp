#include <iostream>
#include <fstream>
#include "Sed.hpp"

int main(int ac, char **av) {
	std::string filePath;
	std::string replaceFile;

	if (ac != 4 || std::string(av[2]).length() < 1) {
		std::cout << "argument error!" << std::endl;
		return 0;
	}

	Sed sed(av[2], av[3]);
	filePath = av[1];
	replaceFile = filePath + ".replace";
	std::ifstream openFile(filePath.data());
	if (!openFile) {
		std::cout << "File Open Error!" << std::endl;
		return 0;
	}
	std::ofstream writeFile(replaceFile.data());
	if (openFile.is_open() && writeFile.is_open()) {
		std::string line;

		while (getline(openFile, line)) {
			sed.replace(line);
			writeFile << line << "\n";
		}
		writeFile.close();
		openFile.close();
	}
}