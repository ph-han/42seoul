#pragma once

#include <iostream>

class Brain
{
private:
	std::string _idea[100];

public:
	Brain();
	virtual ~Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &obj);

	const std::string &getIdeaOne(const size_t idx) const;

};