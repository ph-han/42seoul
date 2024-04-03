#pragma once

#include <stack>
#include <iostream>

class RPN
{
	private:
		std::string _exp;

		RPN();
		
		int char2int(char input);
	public:
		~RPN();
		const RPN& operator= (const RPN& copy);
		RPN(const RPN& copy);
		RPN(char* expression);

		void calc(void);
};