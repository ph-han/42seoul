#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}

		~MutantStack() {}

		const MutantStack& operator=(const MutantStack& copy) 
		{
			if (this != &copy)
				std::stack<T>::operator=(copy);

			return *this;
		}

		MutantStack(const MutantStack& copy)
		{
			MutantStack::operator=(copy);
		}

		typename std::stack<T>::container_type::iterator begin(void)
		{
			return std::stack<T>::c.begin();
		}

		typename std::stack<T>::container_type::iterator end(void)
		{
			return std::stack<T>::c.end();
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
};

