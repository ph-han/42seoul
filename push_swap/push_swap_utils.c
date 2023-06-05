/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:54:09 by phan              #+#    #+#             */
/*   Updated: 2023/06/04 16:46:50 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return ((sign * result));
}

int	ft_max(t_stack st, int chunk_size)
{
	int	max;

	max = top(&st);
	while (chunk_size--)
	{
		if (max < st.top->item)
			max = st.top->item;
		st.top = st.top->next;
	}
	return (max);
}

int	ft_min(t_stack st, int chunk_size)
{
	int	min;

	min = top(&st);
	while (chunk_size--)
	{
		if (min > st.top->item)
			min = st.top->item;
		st.top = st.top->next;
	}
	return (min);
}

int	ft_find(t_stack st, int item)
{
	while (st.top)
	{
		if (st.top->item == item)
			return (st.top->idx);
		st.top = st.top->next;
	}
	return (-1);
}

int	ft_is_valid(t_stack st, char *s)
{
	long	s2l;
	char	*tmp;

	tmp = s;
	if (ft_strlen(s) == 0)
		return (0);
	if (ft_strlen(s) == 1 && (*s == '-' || *s == '+'))
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	s2l = ft_atol(tmp);
	if (s2l > 2147483647 || s2l < -2147483648)
		return (0);
	if (st.size && ft_find(st, s2l) >= 0)
		return (0);
	return (1);
}
