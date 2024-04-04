#include "RPN.hpp" 

RPN::~RPN() {}

const RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
        _exp = copy._exp;

	return *this;
}
 
RPN::RPN(const RPN &copy)
{
	if (this != &copy)
        _exp = copy._exp;
}

RPN::RPN(char* expression) : _exp(expression) {}

int RPN::char2int(char input)
{
	return input - '0';
}

void RPN::calc(void)
{
	std::stack<int> operands;
	bool errFlag = false;

	for (size_t i = 0; i < _exp.length(); i++)
	{

		if (_exp[i] == ' ')
			continue;

		bool isOperator = ((_exp[i] == '+') || (_exp[i] == '-') || (_exp[i] == '*') || (_exp[i] == '/'));
		bool isOperand = (_exp[i] >= '0' && _exp[i] <= '9');

		if (isOperand == false && isOperator == false)
		{
			errFlag = true;
			break;
		}

		if (isOperand)
			operands.push(char2int(_exp[i]));
		else if (operands.size() < 2)
        {
            errFlag = true;
            break;
        }
		else
		{
			int b = operands.top(); operands.pop();
			int a = operands.top(); operands.pop();
			if (_exp[i] == '+')
				operands.push(a + b);
			else if (_exp[i] == '-')
				operands.push(a - b);
			else if (_exp[i] == '/')
			{
				if (b == 0)
				{
					errFlag = true;
					break;
				}
				operands.push(a / b);
			}
			else
				operands.push(a * b);
		}
		
		
	}

	if (errFlag || operands.size() > 1)
		std::cout << "Error" << std::endl;
	else
		std::cout << operands.top() << std::endl;
}
