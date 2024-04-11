#include "PmergeMe.hpp"

PmergeMe::~PmergeMe()
{
	// for (size_t i = 0; i < _mainChain.size(); i++)
	// {
	// 	std::deque<Node*>::iterator it = (_mainChain.begin() + i)->pendingElements.begin();
	// 	size_t pendingElementsSize = (_mainChain.begin() + i)->pendingElements.size();
	// 	for (size_t j = 0; j < pendingElementsSize; j++)
	// 		delete *(it + j);
	// }
	// for (size_t i = 0; i < _remain.size(); i++)
	// {
	// 	std::deque<Node*>::iterator it = (_remain.begin() + i)->pendingElements.begin();
	// 	size_t pendingElementsSize = (_remain.begin() + i)->pendingElements.size();
	// 	for (size_t j = 0; j < pendingElementsSize; j++)
	// 		delete *(it + j);
	// }
	// for (size_t i = 0; i < _list_mainChain.size(); i++)
	// {
	// 	std::deque<Node *>::iterator it = std::next(_list_mainChain.begin(), i)->pendingElements.begin();
	// 	size_t pendingElementsSize = std::next(_list_mainChain.begin(), i)->pendingElements.size();
	// 	for (size_t j = 0; j < pendingElementsSize; j++)
	// 		delete *(it + j);
	// }
	// for (size_t i = 0; i < _list_remain.size(); i++)
	// {
	// 	std::deque<Node *>::iterator it = std::next(_list_remain.begin(), i)->pendingElements.begin();
	// 	size_t pendingElementsSize = std::next(_list_remain.begin(), i)->pendingElements.size();
	// 	for (size_t j = 0; j < pendingElementsSize; j++)
	// 		delete *(it + j);
	// }
}

const PmergeMe &PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_mainChain = copy._mainChain;
		_remain = copy._remain;
		_list_mainChain = copy._list_mainChain;
		_list_remain = copy._list_remain;
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
		_list_mainChain = copy._list_mainChain;
		_list_remain = copy._list_remain;
		_jacobsthalNumList = copy._jacobsthalNumList;
		_errFlag = copy._errFlag;
	}
}

PmergeMe::PmergeMe(): _errFlag(false) {}

void PmergeMe::setElements(int argc, char** argv)
{
	int tmp = -1;

	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		iss >> tmp;
		if (iss.fail() || iss.eof() != true || tmp < 0)
		{
			_errFlag = true;
			break;
		}
		Node tmpNode;
		tmpNode.data = tmp;
		tmpNode.depth = 0;
		tmpNode.mainData = -1;
		_mainChain.push_back(tmpNode);
		_list_mainChain.push_back(tmpNode);
	}
	makeJacobsthalNumbers();
}

void PmergeMe::print(const char* msg)
{
	std::deque<Node>::iterator it = _mainChain.begin();
	std::deque<Node>::iterator ite = _mainChain.end();

	std::cout << msg;
	while (it != ite)
	{
		std::cout << it->data << " ";
		// if (it->pendingElements.size() != 0)
		// {
		// 	std::cout << " | pending elements : ";
		// 	for (unsigned int i = 0; i < it->pendingElements.size(); i++)
		// 		std::cout << "(" << (*(it->pendingElements.begin() + i))->data << ", "
		// 				<< "depth : " << (*(it->pendingElements.begin() + i))->depth << ") ";
		// 	std::cout << std::endl;
		// }
		it++;
	}
	std::cout << std::endl;
}

size_t PmergeMe::findIdx(int data)
{
	std::deque<Node>::iterator head = _mainChain.begin();
	size_t idx;

	for (idx = 0; idx < _mainChain.size(); idx++)
		if (data == (head + idx)->data)
			break ;

	return idx;   
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
			std::iter_swap(it, (it + 1));
		Node* pendingElement = new Node(*(it + 1));
		pendingElement->mainData = it->data;
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

	for (size_t idx = 2; idx < _jacobsthalNumList.size(); idx++)
	{
		int start = *(it + idx) - 1;
		if (start >= static_cast<int>(b.size()))
			start = b.size() - 1;
		int end = (idx == 2) ? -1 : *(it + idx - 1) - 1;
		while (start > end)
		{
			size_t high = (b.begin() + start)->mainData != -1 ? findIdx((b.begin() + start)->mainData) : _mainChain.size();
			insertIdx = binarySearch(0, high, (b.begin() + start)->data);
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
			delete *it;
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

void PmergeMe::list_mergeInsertionSort()
{
	list_merge();
	list_insertion();
}

size_t PmergeMe::list_findIdx(int data)
{
	std::list<Node>::iterator head = _list_mainChain.begin();
	std::list<Node>::iterator tail = _list_mainChain.end();
	size_t idx = 0;

	while (head != tail)
	{
		if (data == head->data)
			break;
		idx++;
		head++;
	}

	return idx;
}

void PmergeMe::list_merge()
{
	if (_list_mainChain.size() == 1)
		return;

	std::list<Node>::iterator it = _list_mainChain.begin();

	int maxLoop = _list_mainChain.size() / 2;
	int iter = 0;
	while (iter < maxLoop)
	{
		if (it->data < std::next(it)->data)
			std::iter_swap(it, std::next(it));
		Node *pendingElement = new Node(*(std::next(it)));
		pendingElement->mainData = it->data;
		it->pendingElements.push_front(pendingElement);
		it->depth += 1;
		iter++;
		it = std::next(it, 2);
	}

	if (it != _list_mainChain.end())
	{
		_list_remain.push_front(*(std::prev(_list_mainChain.end())));
		_list_mainChain.erase(std::prev(_list_mainChain.end()));
	}

	it = _list_mainChain.begin();
	for (unsigned int idx = 1; idx < _list_mainChain.size(); idx++)
	{
		_list_mainChain.erase(std::next(it, idx));
	}
	list_merge();
}

void PmergeMe::list_insertion()
{
	std::deque<Node> b;
	int insertIdx = -1;

	if (list_getCurrMaxDepth() == 0)
		return;

	list_getSameDepthElements(b);

	std::deque<int>::iterator it = _jacobsthalNumList.begin();

	for (size_t idx = 2; idx < _jacobsthalNumList.size(); idx++)
	{
		int start = *(it + idx) - 1;
		if (start >= static_cast<int>(b.size()))
			start = b.size() - 1;
		int end = (idx == 2) ? -1 : *(it + idx - 1) - 1;
		while (start > end)
		{
			size_t high = (b.begin() + start)->mainData != -1 ? list_findIdx((b.begin() + start)->mainData) : _list_mainChain.size();
			insertIdx = list_binarySearch(0, high, (b.begin() + start)->data);
			_list_mainChain.insert(std::next(_list_mainChain.begin(), insertIdx), *(b.begin() + start));
			--start;
		}
	}
	list_insertion();
}

int PmergeMe::list_binarySearch(int low, int high, int target)
{
	int mid = (low + high) / 2;
	std::list<Node>::iterator beginMain = _list_mainChain.begin();

	if (high < 0)
		return 0;

	if (low >= static_cast<int>(_list_mainChain.size()))
		return _list_mainChain.size();

	if (low >= high)
	{
		if (std::next(beginMain, high)->data < target)
			return mid + 1;
		return mid;
	}

	if (std::next(beginMain, mid)->data == target)
		return mid;
	else if (std::next(beginMain, mid)->data > target)
		return list_binarySearch(low, mid - 1, target);
	else
		return list_binarySearch(mid + 1, high, target);
}

void PmergeMe::list_getSameDepthElements(std::deque<Node> &b)
{
	for (size_t idx = 0; idx < _list_mainChain.size(); idx++)
	{
		std::deque<Node *>::iterator it = std::next(_list_mainChain.begin(), idx)->pendingElements.begin();
		std::deque<Node *>::iterator ite = std::next(_list_mainChain.begin(), idx)->pendingElements.end();

		int maxDepth = list_getCurrMaxDepth();

		while (it != ite)
		{
			if (maxDepth - 1 != (*it)->depth)
				break;
			b.push_back(*(*it));
			delete *it;
			std::next(_list_mainChain.begin(), idx)->pendingElements.pop_front();
			it = std::next(_list_mainChain.begin(), idx)->pendingElements.begin();
		}
		if (std::next(_list_mainChain.begin(), idx)->depth == maxDepth)
			std::next(_list_mainChain.begin(), idx)->depth--;
	}

	if (_list_remain.empty() == false && _list_mainChain.front().depth == _list_remain.front().depth)
	{
		b.push_back(_list_remain.front());
		_list_remain.pop_front();
	}
}

int PmergeMe::list_getCurrMaxDepth()
{
	int maxDepth = _list_mainChain.front().depth;
	for (size_t idx = 0; idx < _list_mainChain.size(); idx++)
	{
		if (maxDepth < std::next(_list_mainChain.begin(), idx)->depth)
			maxDepth = std::next(_list_mainChain.begin(), idx)->depth;
	}
	return maxDepth;
}

bool PmergeMe::error()
{
	return _errFlag;
}

size_t PmergeMe::getElementsSize()
{
	return _mainChain.size();
}
