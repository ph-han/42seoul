/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:51:00 by phan              #+#    #+#             */
/*   Updated: 2023/06/18 17:32:08 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *st, int chunk_size)
{
	t_stack	cur;

	if (st->size <= 1)
		return (1);
	cur = *st;
	while (chunk_size-- && cur.top->next)
	{
		if (cur.top->item > cur.top->next->item)
			return (0);
		cur.top = cur.top->next;
	}
	return (1);
}

static int	q_sort_3_a_edge_case(t_stack *a, int min, int max)
{
	if (top(a) == min)
	{
		ra(a);
		sa(a);
		rra(a);
		return (1);
	}
	if (a->top->next->next->item == max)
	{
		if (top(a) > a->top->next->item)
			sa(a);
		return (1);
	}
	return (0);
}

static int	q_sort_3_b_edge_case(t_stack *a, t_stack *b, int min)
{
	if (b->top->next->next->item == min)
	{
		if (top(b) < b->top->next->item)
			sb(b);
		pa(a, b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	return (0);
}

void	q_sort_3_a(t_stack *a, t_stack *b, int chunk_size, int ra_cnt)
{
	int	max;
	int	min;

	if (is_sorted(a, chunk_size))
		return ;
	max = ft_max(*a, chunk_size);
	min = ft_min(*a, chunk_size);
	if (q_sort_3_a_edge_case(a, min, max))
		return ;
	while (chunk_size--)
	{
		if (max == a->top->item)
		{
			if (chunk_size)
				ra_cnt += ra(a);
		}
		else
			pb(a, b);
	}
	if (top(b) < b->top->next->item)
		sb(b);
	while (ra_cnt--)
		rra(a);
	pa(a, b);
	pa(a, b);
}

void	q_sort_3_b(t_stack *a, t_stack *b, int chunk_size, int rb_cnt)
{
	int	min;

	min = ft_min(*b, chunk_size);
	if (q_sort_3_b_edge_case(a, b, min))
		return ;
	while (chunk_size--)
	{
		if (min == top(b))
		{
			if (chunk_size)
				rb_cnt += rb(b);
		}
		else
			pa(a, b);
	}
	if (top(a) > a->top->next->item)
		sa(a);
	while (rb_cnt--)
		rrb(b);
	pa(a, b);
}
