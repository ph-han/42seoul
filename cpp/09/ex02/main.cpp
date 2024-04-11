#include "PmergeMe.hpp"

void leak_check()
{
	system("leaks PmergeMe");
}

int main(int ac, char** av)
{
	atexit(leak_check);
	if (ac < 2)
	{
		std::cout << "Error: Input arguments" << std::endl;
		return 1;
	}

	PmergeMe pmergeme;
	clock_t start, end;

	pmergeme.setElements(ac, av);
	if (pmergeme.error())
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	pmergeme.print("Befor:\t");
	start = clock();
	pmergeme.mergeInsertionSort();
	end = clock();
	pmergeme.print("After:\t");

	double time = (static_cast<double>(end - start)) / 1000.0;
	std::cout << "Time to process a range of " << pmergeme.getElementsSize() << " elements with std::deque : " << time << " us" << std::endl;
	start = clock();
	pmergeme.list_mergeInsertionSort();
	end = clock();

	time = (static_cast<double>(end - start)) / 1000.0;
	std::cout << "Time to process a range of " << pmergeme.getElementsSize() << " elements with std::list : " << time << " us" << std::endl;
	return 0;
}
