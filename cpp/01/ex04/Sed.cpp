#include "Sed.hpp"

Sed::Sed(std::string originWord, std::string replaceWord) : _originWord(originWord), _replaceWord(replaceWord) {

}

void Sed::replace(std::string &line) {
	std::size_t replaceIdx = line.find(_originWord);

	while (replaceIdx != std::string::npos) {
		line.erase(replaceIdx, _originWord.length());
		line.insert(replaceIdx, _replaceWord);
		replaceIdx = line.find(_originWord);
	}
}