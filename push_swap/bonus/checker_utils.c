/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:16:03 by phan              #+#    #+#             */
/*   Updated: 2023/06/22 11:42:32 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static int	ft_find(t_stack st, int item)
{
	while (st.top)
	{
		if (st.top->item == item)
			return (st.top->idx);
		st.top = st.top->next;
	}
	return (-1);
}

int	is_valid(t_stack st, char *s)
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

static int	input_data_free_all(char **inputs)
{
	int	idx;

	idx = 0;
	while (inputs[idx])
		free(inputs[idx++]);
	free(inputs);
	return (-1);
}

int	input_data(t_stack *a, int idx, char *argv[])
{
	char	**inputs;
	int		input_num;

	while (idx > 0)
	{
		inputs = ft_split(argv[idx], ' ');
		input_num = 0;
		while (inputs[input_num])
			input_num++;
		if (input_num == 0)
		{
			free(inputs);
			return (-1);
		}
		while (input_num)
		{
			if (!is_valid(*a, inputs[--input_num]))
				return (input_data_free_all(inputs));
			push(ft_atoi(inputs[input_num]), a);
		}
		input_data_free_all(inputs);
		idx--;
	}
	return (1);
}
