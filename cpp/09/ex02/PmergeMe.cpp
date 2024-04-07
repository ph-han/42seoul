#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {}

const PmergeMe &PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_mainChain = copy._mainChain;
		_errFlag = copy._errFlag;
	}

	return *this;
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_mainChain = copy._mainChain;
		_errFlag = copy._errFlag;
	}
}

PmergeMe::PmergeMe(int argc, char** argv): _errFlag(false)
{
	int tmp = -1;

	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		iss >> tmp;
		if (iss.fail() || iss.eof() != true || tmp < 0)
		{
			_errFlag = true;
			break ;
		}
		_mainChain.push_back(tmp);
	}
}

void PmergeMe::print(const char* msg, int flag)
{
	std::deque<int>::iterator it = _mainChain.begin();
	std::deque<int>::iterator ite = _mainChain.end();

	std::cout << msg;
	if (flag == ITEM)
	{
		while (it != ite)
		{
			std::cout << *it << " ";
			it++;
		}
	}
	else
	{
		std::cout << "62.123123 us";
	}
	std::cout << std::endl;
}

void PmergeMe::swap(std::deque<int>::iterator* a, std::deque<int>::iterator* b, int size)
{
	int iter = 0;

	while (iter < size)
	{
		int tmp = *(*b);
		*(*b) = *(*b);
		*(*b) = tmp;
		(*a)++;
		(*b)++;
		iter++;
	}
}

int PmergeMe::divide(int pairSize)
{
	if (_mainChain.size() / pairSize == 0)
	{
		return pairSize / 2;
	}
	
	std::deque< int >::iterator it = _mainChain.begin();
	
	int maxLoop = _mainChain.size() / pairSize;
	int iter = 0;

	while (iter < maxLoop)
	{
		if (*it < *(it + pairSize / 2))
		{
			int idx = -1;
			while (++idx < pairSize / 2)
				std::swap(*(it + idx), *(it + (pairSize / 2) + idx));
		}
		iter++;
		it += pairSize;
	}
	return divide(pairSize * 2);
}

void PmergeMe::conquer()
{

}

void PmergeMe::mergeInsertionSort()
{
	std::cout << "max pair : " << divide(2) << std::endl;
	// conquer();
}

bool PmergeMe::error()
{
	return _errFlag;
}

/**
 *
 * (19 / 5) (8 / 3) (15 / 4) (30 / 28) (29 / 7) (10 / 2) (31 / 6) (24 / 14) (25 / 1) (17 9) (26 18) (20 12) (27 16) (21 13) (23 22) 11
 * (19 5 8 3) (30 28 15 4) (29 7 10 2) (31 6 24 14) (25 1 17 9) (26 18 20 12) (27 16 21 13) (23 22) 11
 * (30 28 15 4 19 5 8 3) (31 6 24 14 29 7 10 2) (26 18 20 12 25 1 17 9) (27 16 21 13) (23 22) 11
 * (31 6 24 14 29 7 10 2 / 30 28 15 4 19 5 8 3) 26 18 20 12 25 1 17 9 27 16 21 13 23 22 11
 */