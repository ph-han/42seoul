#include "PmergeMe.hpp"

PmergeMe::~PmergeMe()
{
	for (size_t i = 0; i < _mainChain.size(); i++)
	{
		std::deque<Node*>::iterator it = (_mainChain.begin() + i)->pendingElements.begin();
		size_t pendingElementsSize = (_mainChain.begin() + i)->pendingElements.size();
		for (size_t j = 0; j < pendingElementsSize; j++)
			delete *(it + j);
	}
	for (size_t i = 0; i < _remain.size(); i++)
	{
		std::deque<Node*>::iterator it = (_remain.begin() + i)->pendingElements.begin();
		size_t pendingElementsSize = (_remain.begin() + i)->pendingElements.size();
		for (size_t j = 0; j < pendingElementsSize; j++)
			delete *(it + j);
	}
}

const PmergeMe &PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_mainChain = copy._mainChain;
		_remain = copy._remain;
		_jacobsthalNumList = copy._jacobsthalNumList;
		_errFlag = copy._errFlag;
	}

	return *this;
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_mainChain = copy._mainChain;
		_remain = copy._remain;
		_jacobsthalNumList = copy._jacobsthalNumList;
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
		test.push_back(tmp);
		Node tmpNode;
		tmpNode.data = tmp;
		tmpNode.depth = 0;
		_mainChain.push_back(tmpNode);
	}
	makeJacobsthalNumbers();
}

void PmergeMe::print(const char* msg, int flag)
{
	std::deque<Node>::iterator it = _mainChain.begin();
	std::deque<Node>::iterator ite = _mainChain.end();

	std::cout << msg;
	if (flag == ITEM)
	{
		while (it != ite)
		{
			std::cout << it->data << " ";
			if (it->pendingElements.size() != 0)
			{
				std::cout << " | pending elements : ";
				for (unsigned int i = 0; i < it->pendingElements.size(); i++)
					std::cout << "(" << (*(it->pendingElements.begin() + i))->data << ", "
							<< "depth : " << (*(it->pendingElements.begin() + i))->depth << ") ";
				std::cout << std::endl;
			}
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

	merge();
}

void PmergeMe::insertion()
{
	std::deque<Node> b;
	int insertIdx = -1;

	if (getCurrMaxDepth() == 0)
		return ;

	getSameDepthElements(b);

	std::deque<int>::iterator it = _jacobsthalNumList.begin();

	for (size_t idx = 0; idx < _jacobsthalNumList.size(); idx++)
	{
		int start = *(it + idx);
		if (start >= static_cast<int>(b.size()))
			start = b.size() - 1;
		int end = (idx == 0) ? -1 : *(it + idx - 1);
		while (start > end)
		{
			insertIdx = binarySearch(0, _mainChain.size(), (b.begin() + start)->data);
			_mainChain.insert(_mainChain.begin() + insertIdx, *(b.begin() + start));
			--start;
		}
	}

	insertion();
}


int PmergeMe::binarySearch(int low, int high, int target)
{
	int mid = (low + high) / 2;
	std::deque<Node>::iterator beginMain = _mainChain.begin();

	if (high < 0)
		return 0;

	if (low >= static_cast<int>(_mainChain.size()))
		return _mainChain.size();

	if (low >= high)
	{
		if ((beginMain + high)->data < target)
			return mid + 1;
		return mid;
	}

	if ((beginMain + mid)->data == target)
		return mid;
	else if ((beginMain + mid)->data > target)
		return binarySearch(low, mid - 1, target);
	else
		return binarySearch(mid + 1, high, target);
}

void PmergeMe::getSameDepthElements(std::deque<Node>& b)
{
	for (size_t idx = 0; idx < _mainChain.size(); idx++)
	{
		std::deque<Node*>::iterator it = (_mainChain.begin() + idx)->pendingElements.begin();
		std::deque<Node*>::iterator ite = (_mainChain.begin() + idx)->pendingElements.end();

		int maxDepth = getCurrMaxDepth();

		while (it != ite)
		{
			if (maxDepth - 1 != (*it)->depth)
				break ;
			b.push_back(*(*it));
			(_mainChain.begin() + idx)->pendingElements.pop_front();
			it = (_mainChain.begin() + idx)->pendingElements.begin();
		}
		if ((_mainChain.begin() + idx)->depth == maxDepth)
			(_mainChain.begin() + idx)->depth--;
	}

	if (_remain.empty() == false && _mainChain.front().depth == _remain.front().depth)
	{
		b.push_back(_remain.front());
		_remain.pop_front();
	}
}

int PmergeMe::getCurrMaxDepth()
{
	int maxDepth = _mainChain.front().depth;
	for (size_t idx = 0; idx < _mainChain.size(); idx++)
	{
		if (maxDepth < (_mainChain.begin() + idx)->depth)
			maxDepth = (_mainChain.begin() + idx)->depth;
	}
	return maxDepth;
}

void PmergeMe::makeJacobsthalNumbers()
{
	int N = (_mainChain.size() / 2) + (_mainChain.size() % 2);

	_jacobsthalNumList.push_back(0);
	_jacobsthalNumList.push_back(1);

	int i = 2;
	while (true)
	{
		int currNum = *(_jacobsthalNumList.begin() + (i - 2)) + *(_jacobsthalNumList.begin() + (i - 1));
		_jacobsthalNumList.push_back(currNum);
		if (currNum > N)
			break ;
		i++;
	}
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
