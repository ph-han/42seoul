#pragma once

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