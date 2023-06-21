/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:13 by phan              #+#    #+#             */
/*   Updated: 2023/06/21 15:29:02 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_stack *st)
{
	t_node	*tmp;

	while (st->top)
	{
		tmp = st->top;
		st->top = st->top->next;
		free(tmp);
	}
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

static int	input_data(t_stack *a, int idx, char *argv[])
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
			if (!ft_is_valid(*a, inputs[--input_num]))
				return (input_data_free_all(inputs));
			push(ft_atoi(inputs[input_num]), a);
		}
		input_data_free_all(inputs);
		idx--;
	}
	return (1);
}

static void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
	{
		sort_3(a);
		return ;
	}
	if (a->size <= 5)
	{
		sort_5(a, b);
		return ;
	}
	quick_sort(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init(&a);
	if (argc < 2)
		return (-1);
	if (input_data(&a, argc - 1, argv) == -1)
	{
		if (a.top)
			free_all(&a);
		return ((write(2, "Error\n", 6) * 0) + -1);
	}
	init(&b);
	push_swap(&a, &b);
	free_all(&a);
	return (0);
}
