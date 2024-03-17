#pragma once

#include <iostream>

struct Data
{
	int data;
};


class Serializer
{
	private:
		Serializer();
		const Serializer& operator=(const Serializer& copy);
		Serializer(const Serializer& copy);
	public:
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};