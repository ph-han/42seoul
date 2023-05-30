/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:50:03 by phan              #+#    #+#             */
/*   Updated: 2023/05/30 16:05:49 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	int	max;

	if (a->size < 2)
		return ;
	max = ft_max(*a);
	if (top(a) == max)
		ra(a);
	if (a->top->next->next)
	{
		if (a->top->next->item > a->top->next->next->item)
			rra(a);
		if (top(a) > a->top->next->item)
			sa(a);
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min;
	int	mid;
	int	idx;

	while (a->size > 3)
	{
		mid = a->size / 2;
		min = ft_min(*a);
		idx = ft_find(*a, min);
		if (idx + 1 == a->size - 1)
			sa(a);
		while (top(a) != min)
		{
			if (mid < idx)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_3(a);
	while (b->top)
		pa(a, b);
}
