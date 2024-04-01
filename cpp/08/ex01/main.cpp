#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	std::vector<int> items;
	items.push_back(6);
	items.push_back(3);
	items.push_back(17);
	items.push_back(9);
	items.push_back(11);
	Span sp2 = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	sp2.addNumber(items);
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	return 0;
}