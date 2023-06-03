/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:50:03 by phan              #+#    #+#             */
/*   Updated: 2023/05/31 19:01:50 by phan             ###   ########.fr       */
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

void	q_sort_3(t_stack *a, t_stack *b)
{
	int	min;
	int	ra_cnt;

	min = ft_min(*a);
	ra_cnt = 0;
	while (top(a) != min)
	{
		ra_cnt++;
		ra(a);
	}
	pb(a, b);
	while (ra_cnt--)
		rra(a);
	if (a->top->item > a->top->next->item)
		sa(a);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min;
	int	mid;
	int	idx;
	int	pb_cnt;

	pb_cnt = 0;
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
		pb_cnt++;
	}
	sort_3(a);
	while (pb_cnt--)
		pa(a, b);
}
