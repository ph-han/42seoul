#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class A;
class B;
class C;

Base::~Base()
{
}

Base *Base::generate(void)
{
	int idx;

	idx = std::rand() % 3;
	if (idx == 0)
		return new A();
	else if (idx == 1)
		return new B();
	else
		return new C();
}

void Base::identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a != NULL)
		std::cout << "I'm A" << std::endl; 

	if (b != NULL)
		std::cout << "I'm B" << std::endl;

	if (c != NULL)
		std::cout << "I'm C" << std::endl; 
}

void Base::identify(Base &p)
{

	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "I'm A" << std::endl;
	}
	catch(std::exception e)
	{
		
	}

	try
	{
		B& b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "I'm B" << std::endl;
	}
	catch(std::exception e)
	{
		
	}

	try
	{
		C& c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "I'm C" << std::endl;
	}
	catch(std::exception e)
	{
		
	}

}
