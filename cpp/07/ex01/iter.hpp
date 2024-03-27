#pragma once

#include <iostream>

template <typename T>
void increase(T &a)
{
	a += 1;
}

template <typename T>
void iter(T* addr, size_t len, void (*f)(T&))
{
	for (size_t i = 0; i < len; i++)
		f(addr[i]);
}

template <typename T>
void iter(T* addr, size_t len, void (*f)(const T&))
{
	for (size_t i = 0; i < len; i++)
		f(addr[i]);
}