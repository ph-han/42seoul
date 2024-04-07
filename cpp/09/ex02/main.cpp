#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cout << "Error: Input arguments" << std::endl;
		return 1;
	}

	PmergeMe pmergeme(ac, av);

	if (pmergeme.error())
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	pmergeme.print("Befor:\t", ITEM);
	pmergeme.mergeInsertionSort();
	// pmergeme.print("After:\t", ITEM);

	return 0;
}