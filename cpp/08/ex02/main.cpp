#include <iostream>
#include "MutantStack.hpp"

int main(void)
{
	std::cout << "=========== stack member function ===========" << std::endl;
	std::cout << "make stack" << std::endl;
	MutantStack<int> mstack;
	std::cout << "push(5)" << std::endl;
	mstack.push(5);
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "push(17)" << std::endl;
	mstack.push(17);
	std::cout << "top : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "pop()" << std::endl;
	std::cout << "top : " << mstack.top() << std::endl;

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...]
	mstack.push(0);

	std::cout << "=========== iterator check ===========" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while(it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "=========== std stack copy constructor check ===========" << std::endl;
	std::stack<int> s(mstack);
	while (s.empty() == false)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "=========== mutant stack copy constructor check ===========" << std::endl;
	MutantStack<int> ccMstack(mstack);
	MutantStack<int>::reverse_iterator it2 = ccMstack.rbegin();
	MutantStack<int>::reverse_iterator ite2 = ccMstack.rend();
	// ++it2;
	// --it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::cout << "=========== empty check ===========" << std::endl;
	while (mstack.size() > 0)
	{
		std::cout << mstack.top() << std::endl;
		mstack.pop();
	}
	if (mstack.empty())
		std::cout << "mstack is empty!" << std::endl;

	std::cout << "=========== mutant stack copy operator check ===========" << std::endl;
	MutantStack<int> coMstack;
	coMstack = ccMstack;
	while (coMstack.empty() == false)
	{
		std::cout << coMstack.top() << std::endl;
		coMstack.pop();
	}
	return 0;
}