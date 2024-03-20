#include "Base.hpp"
#include <unistd.h>

int main()
{
	Base b;

	srand(time(NULL));
	Base *test1 = b.generate();
	b.identify(test1);

	usleep(10000);
	
	Base &test2 = *(b.generate());
	b.identify(test2);

	delete test1;

	return 0;
}