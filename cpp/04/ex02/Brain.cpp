#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_idea[i] = "";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << "Brain copy assignment operator called\n";
	if (this == &obj)
		return *this;
	for (int i = 0; i < 100; i++)
		_idea[i] = obj.getIdeaOne(i);
	return *this;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called\n";
	*this = copy;
}

const std::string &Brain::getIdeaOne(const size_t idx) const
{
	return _idea[idx];
}
