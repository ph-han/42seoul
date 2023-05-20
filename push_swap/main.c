/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:13 by phan              #+#    #+#             */
/*   Updated: 2023/05/20 13:33:47 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *a, t_stack *b)
{
	while (a->top)
	{
		ft_printf("a items : %d\n", top(a));
		if (a->size == 0)
			ft_printf("a stack is empty\n");
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		item;
	int		idx;

	init(&a);
	init(&b);
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	idx = 1;
	while (idx < argc)
	{
		item = ft_atoi(argv[idx]);
		if (item == 0 && *argv[idx] != '0')
		{
			ft_printf("Error\n");
			return (0);
		}
		push(item, &a);
		idx++;
	}
	push_swap(&a, &b);
	return (0);
}
