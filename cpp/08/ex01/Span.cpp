#include "Span.hpp"
#include <iostream>

Span::~Span() {}

Span::Span(unsigned int n) : _max(n), _n(0) {}

Span::Span(const Span &copy)
{
	if (this != &copy)
	{
		_max = copy._max;
		_n = copy._n;
		for (unsigned int i = 0; i < copy._n; i++)
			_dataList[i] = copy._dataList[i];
	}
}

const Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_max = copy._max;
		_n = copy._n;
		for (unsigned int i = 0; i < copy._n; i++)
			_dataList[i] = copy._dataList[i];
	}

	return *this;
}

void Span::addNumber(int input)
{
	if (_max <= _n)
		throw std::exception();

	_dataList.push_back(input);
	std::sort(_dataList.begin(), _dataList.end());
	_n++;
}

void Span::addNumber(std::vector<int> input)
{

	for (size_t i = 0; i < input.size(); i++)
	{
		if (_max <= _n)
			throw std::exception();
		_dataList.push_back(input[i]);
		_n++;
	}
	std::sort(_dataList.begin(), _dataList.end());
}

int Span::shortestSpan()
{
	if (_n < 2)
		throw std::exception();
	unsigned int shortestSpanNum = INT_MAX;
	for (unsigned int i = 0; i < _n - 1; i++)
	{
		unsigned int span = abs(_dataList[i + 1] - _dataList[i]);
		if (span < shortestSpanNum)
			shortestSpanNum = span;
	}
	return shortestSpanNum;
}

int Span::longestSpan()
{
	if (_n < 2)
		throw std::exception();
	return abs(_dataList[_n - 1] - _dataList[0]);
}
