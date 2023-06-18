/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:01:06 by phan              #+#    #+#             */
/*   Updated: 2023/06/18 14:25:13 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	int	max;

	if (a->size < 2)
		return ;
	max = ft_max(*a, a->size);
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
	int	idx;
	int	pb_cnt;

	if (is_sorted(a, a->size))
		return ;
	pb_cnt = 0;
	while (a->size > 3)
	{
		min = ft_min(*a, a->size);
		idx = ft_find(*a, min);
		if (idx + 1 == a->size - 1)
			sa(a);
		while (top(a) != min)
		{
			if (a->size / 2 < idx)
				ra(a);
			else
				rra(a);
		}
		pb_cnt += pb(a, b);
	}
	sort_3(a);
	while (pb_cnt--)
		pa(a, b);
}
