#pragma once

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <exception>

class Span
{
	private:
		unsigned int _max;
		unsigned int _n;

		std::vector<int> _dataList;

		Span();

	public:
		~Span();
		Span(unsigned int n);
		Span(const Span& copy);
		const Span& operator=(const Span& copy);

		void addNumber(int input);

		int shortestSpan();
		int longestSpan();
};