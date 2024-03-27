#pragma once

template <typename T>
typename T::iterator easyfind(T& container, int target)
{
	typename T::iterator iter = container.begin();

	while (iter != container.end())
	{
		if (*iter == target)
			break ;
		iter++;
	}

	return iter;
}