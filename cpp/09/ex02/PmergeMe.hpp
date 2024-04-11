#pragma once

#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
#include <deque>
#include <list>

#define DEQUE 0
#define LIST 1

struct Node
{
	int data;
	int depth;
	int mainData;
	std::deque<Node*> pendingElements;
};

class PmergeMe
{
	private:
		std::deque<Node> _mainChain;
		std::deque<Node> _remain;

		std::list<Node> _list_mainChain;
		std::list<Node> _list_remain;

		std::deque<int> _jacobsthalNumList;
		bool _errFlag;

		size_t findIdx(int data);
		void merge();
		void insertion();
		void getSameDepthElements(std::deque<Node>& b);
		int getCurrMaxDepth();
		int binarySearch(int low, int high, int target);

		size_t list_findIdx(int data);
		void list_merge();
		void list_insertion();
		void list_getSameDepthElements(std::deque<Node>& b);
		int list_getCurrMaxDepth();
		int list_binarySearch(int low, int high, int target);

		void makeJacobsthalNumbers();

		std::list<Node>::iterator next(std::list<Node>::iterator it, size_t n);
		std::list<Node>::iterator prev(std::list<Node>::iterator it, size_t n);
	public:
		PmergeMe();
		~PmergeMe();
		const PmergeMe& operator=(const PmergeMe& copy);
		PmergeMe(const PmergeMe& copy);

		void setElements(int argc, char** argv);
		void print(const char* msg);
		void mergeInsertionSort();
		void list_mergeInsertionSort();
		bool error();

		size_t getElementsSize();
};
