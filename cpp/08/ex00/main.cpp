#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main(void) 
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	int target = 3;

	std::cout << "find : " << *easyfind(v, target) << std::endl;

	target = 6;
	bool isNotFound = (easyfind(v, target) == v.end());

	if (isNotFound)
		std::cout << target << " : Not Found" << std::endl;

}
