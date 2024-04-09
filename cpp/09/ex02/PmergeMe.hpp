#pragma once

#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>

#define ITEM 0
#define TIME 1

struct Node
{
	int data;
	int depth;
	std::deque<Node*> pendingElements;
};

class PmergeMe
{
	private:
		std::deque<Node> _mainChain;
		std::deque<Node> _remain;
		std::deque<int> _jacobsthalNumList;
		bool _errFlag;

		PmergeMe();

		void merge();
		void insertion();
		void makeJacobsthalNumbers();
		void getSameDepthElements(std::deque<Node>& b);
		int getCurrMaxDepth();
		int binarySearch(int low, int high, int target);

	public:
		~PmergeMe();
		const PmergeMe& operator=(const PmergeMe& copy);
		PmergeMe(const PmergeMe& copy);
		PmergeMe(int argc, char** argv);

		void print(const char* msg, int flag);
		void mergeInsertionSort();
		bool error();

		std::deque<int> test;
};
