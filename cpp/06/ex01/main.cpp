#include "Serializer.hpp"

int main()
{
	Data *a;

	a->data = 24;
	
	uintptr_t raw = Serializer::serialize(a);

	std::cout << "raw : " << raw << std::endl;

	Data *b = Serializer::deserialize(raw);
	
	std::cout << "data pointer : " << b << std::endl;
	std::cout << "data : " << b->data << std::endl;

	return 0;
}