/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:13 by phan              #+#    #+#             */
/*   Updated: 2023/05/24 20:49:16 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size < 2)
		return ;
	if (a->top->item > a->top->next->item)
		sa(a);
	if (a->top->next->next)
	{
		if (a->top->next->item > a->top->next->next->item)
			rra(a);
		if (a->top->item > a->top->next->item)
			sa(a);
		if (a->top->next->item > a->top->next->next->item)
			rra(a);
	}
	while (a->top && b)
	{
		ft_printf("%d ", a->top->item);
		a->top = a->top->next;
	}
	return ;
}

// static int	is_valid(char *item)
// {

// }

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		idx;

	init(&a);
	init(&b);
	if (argc < 2)
		return ((ft_printf("Error\n") * 0) + -1);
	idx = argc - 1;
	while (idx > 0)
	{
		// if (is_valid(argv[idx]) == 0)
			// return ((ft_printf("Error\n") * 0) + -1);
		push(ft_atoi(argv[idx]), &a);
		idx--;
	}
	push_swap(&a, &b);
	return (0);
}
