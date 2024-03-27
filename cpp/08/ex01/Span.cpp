#include "Span.hpp"

Span::~Span() {}

Span::Span(unsigned int n) : _max(n), _n(0), _shortestSpanNum(INT_MAX), _longestSpanNum(0) {}

Span::Span(const Span &copy)
{
	if (this != &copy)
	{
		_max = copy._max;
		_n = copy._n;
		for (unsigned int i = 0; i < copy._n; i++)
			_dataList[i] = copy._dataList[i];
		_shortestSpanNum = copy._shortestSpanNum;
		_longestSpanNum = copy._longestSpanNum;
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
		_shortestSpanNum = copy._shortestSpanNum;
		_longestSpanNum = copy._longestSpanNum;
	}

	return *this;
}

void Span::addNumber(int input)
{
	if (_max <= _n)
		throw 1;

	_dataList.push_back(input);
	std::sort(_dataList.begin(), _dataList.end());
	_n++;

	for (unsigned int i = 0; i < _n; i++)
	{
		for (unsigned int j = i + 1; j < _n; j++)
		{
			unsigned int span = abs(_dataList[i] - _dataList[j]);
			if (span < _shortestSpanNum)
				_shortestSpanNum = span;
			if (span > _longestSpanNum)
				_longestSpanNum = span;
		}
	}
	
}

int Span::shortestSpan()
{
	if (_n < 2)
		throw 1;

	return _shortestSpanNum;
}

int Span::longestSpan()
{
	if (_n < 2)
		throw 1;

	return _longestSpanNum;
}
