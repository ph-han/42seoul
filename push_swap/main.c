/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:13 by phan              #+#    #+#             */
/*   Updated: 2023/06/07 14:01:14 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	input_data_free_all(char **inputs)
{
	int idx;

	idx = 0;
	while (inputs[idx])
		free(inputs[idx++]);
}

static int	input_data(t_stack *a, int argc, char *argv[])
{
	int		idx;
	char	**inputs;
	int		input_num;

	idx = argc - 1;
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
			{
				input_data_free_all(inputs);
				free(inputs);
				return (-1);
			}
			push(ft_atoi(inputs[input_num]), a);
		}
		input_data_free_all(inputs);
		free(inputs);
		idx--;
	}
	return (1);
}

void	print_stack(t_stack st, char c)
{
	ft_printf("%c : ", c);
	while (st.top)
	{
		ft_printf("%d ", st.top->item);
		st.top = st.top->next;
	}
	ft_printf("\n");
}

void	free_all(t_stack *st)
{
	t_node *tmp;

	while (st->top)
	{
		tmp = st->top;
		st->top = st->top->next;
		free(tmp);
	}
}

void	leak_check(void)
{
	system("leaks --list -- push_swap");
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init(&a);
	if (argc < 2)
		return ((write(2, "Error\n", 6) * 0) + -1);
	if (input_data(&a, argc, argv) == -1)
	{
		if (a.top)
			free_all(&a);
		return ((write(2, "Error\n", 6) * 0) + -1);
	}
	init(&b);
	// print_stack(a, 'a');
	push_swap(&a, &b);
	// print_stack(a, 'a');
	// print_stack(b, 'b');
	free_all(&a);
	//atexit(leak_check);
	return (0);
}
