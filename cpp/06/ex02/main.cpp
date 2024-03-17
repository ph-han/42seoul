#include "Base.hpp"

int main()
{
	Base b;

	Base *test1 = b.generate();
	b.identify(test1);

	Base &test2 = *(b.generate());
	b.identify(test2);

	return 0;
}