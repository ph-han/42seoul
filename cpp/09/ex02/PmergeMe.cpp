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
		Node tmpNode;
		tmpNode.data = tmp;
		tmpNode.depth = 0;
		_mainChain.push_back(tmpNode);
	}
}

void PmergeMe::print(const char* msg, int flag)
{
	std::deque<Node>::iterator it = _mainChain.begin();
	std::deque<Node>::iterator ite = _mainChain.end();

	std::cout << msg;
	if (flag == ITEM)
	{
		std::cout << "depth : " << it->depth << std::endl;
		while (it != ite)
		{
			std::cout << it->data << " | pending elements : ";
			for (unsigned int i = 0; i < it->pendingElements.size(); i++)
				std::cout << "(" << (*(it->pendingElements.begin() + i))->data << ", "
						  << "depth : " << (*(it->pendingElements.begin() + i))->depth << ") ";
			std::cout << std::endl;
			it++;
		}
	}
	else
	{
		std::cout << "62.123123 us";
	}
	std::cout << std::endl;
}

void PmergeMe::merge()
{
	if (_mainChain.size() == 1)
		return ;

	std::deque<Node>::iterator it = _mainChain.begin();

	int maxLoop = _mainChain.size() / 2;
	int iter = 0;
	while (iter < maxLoop)
	{
		if (it->data < (it + 1)->data)
			std::swap(*it, *(it + 1));
		Node *pendingElement = new Node(*(it + 1));
		it->pendingElements.push_front(pendingElement);
		it->depth += 1;
		it += 2;
		iter++;
	}

	if (it != _mainChain.end())
	{
		_remain.push_front(*(_mainChain.end() - 1));
		_mainChain.erase(_mainChain.end() - 1);
	}

	for (unsigned int idx = 1; idx < _mainChain.size(); idx++)
	{
		_mainChain.erase(_mainChain.begin() + idx);
	}

	print("merge : ", ITEM);
	merge();
}

void PmergeMe::insertion()
{
	if (_mainChain.begin()->depth == 0)
		return ;

	int sameDepthNum = countSameDepth();
	// std::deque<Node>::iterator it = _mainChain.begin();
	// int maxLoop = _mainChain.size() / pairSize;

	// std::cout << "pairSize : " << pairSize << std::endl;
	// int iter = 0;
	// while (iter < maxLoop)
	// {
	// 	if (*it < *(it + pairSize / 2))
	// 	{
	// 		int idx = -1;
	// 		while (++idx < pairSize / 2)
	// 			std::swap(*(it + idx), *(it + (pairSize / 2) + idx));
	// 	}
	// 	iter++;
	// 	it += pairSize;
	// }
	// insertion(pairSize / 2);
}

int PmergeMe::binarySearch(int low, int high, int target)
{
	return 0;	
}

void PmergeMe::mergeInsertionSort()
{
	merge();
	insertion();
}

bool PmergeMe::error()
{
	return _errFlag;
}

/**
 *
 * (19 / 5) (8 / 3) (15 / 4) (30 / 28) (29 / 7) (10 / 2) (31 / 6) (24 / 14) (25 / 1) (17 9) (26 18) (20 12) (27 16) (21 13) (23 22) 11
 * (19 5 / 8 3) (30 28 / 15 4) (29 7 / 10 2) (31 6 / 24 14) (25 1 / 17 9) (26 18 / 20 12) (27 16 / 21 13) (23 22) 11
 * (30 28 15 4 19 5 8 3) (31 6 24 14 29 7 10 2) (26 18 20 12 25 1 17 9) (27 16 21 13) (23 22) 11
 * (31 6 24 14 29 7 10 2  / 30 28 15 4 19 5 8 3) 26 18 20 12 25 1 17 9 27 16 21 13 23 22 11
 */