/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:13 by phan              #+#    #+#             */
/*   Updated: 2023/05/30 16:00:40 by phan             ###   ########.fr       */
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
		sort_10_under(a, b);
		return ;
	}
	// quick_sort();
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
		while (input_num)
		{
			if (!ft_is_valid(*a, inputs[--input_num]))
				return ((ft_printf("Error\n") * 0) + -1);
			push(ft_atoi(inputs[input_num]), a);
		}
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

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init(&a);
	init(&b);
	if (argc < 2)
		return ((ft_printf("Error\n") * 0) + -1);
	if (input_data(&a, argc, argv) == -1)
		return (-1);
	print_stack(a, 'a');
	push_swap(&a, &b);
	print_stack(a, 'a');
	return (0);
}
