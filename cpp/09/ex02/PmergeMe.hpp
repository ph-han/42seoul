#pragma once

#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>

#define ITEM 0
#define TIME 1

class PmergeMe
{
	private:
		std::deque< int > _mainChain;
		std::deque< int > _pendingElements;
		bool _errFlag;
		
		PmergeMe();

		void swap(std::deque<int>::iterator* a, std::deque<int>::iterator* b, int size);
		int divide(int pairSize);
		void conquer();
	public:
		~PmergeMe();
		const PmergeMe& operator=(const PmergeMe& copy);
		PmergeMe(const PmergeMe& copy);
		PmergeMe(int argc, char** argv);

		void print(const char* msg, int flag);
		void mergeInsertionSort();
		bool error();
};