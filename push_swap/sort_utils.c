/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:50:03 by phan              #+#    #+#             */
/*   Updated: 2023/06/07 14:00:45 by phan             ###   ########.fr       */
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

void	q_sort_3(t_stack *a, t_stack *b, int chunk_size)
{
	int	max;
	int	min;
	int	ra_cnt;

	if (is_sorted(a, chunk_size))
		return ;
	max = ft_max(*a, chunk_size);
	min = ft_min(*a, chunk_size);
	if (top(a) == min)
	{
		ra(a);
		sa(a);
		rra(a);
		return ;
	}
	if (a->top->next->next->item == max)
	{
		if (top(a) > a->top->next->item)
			sa(a);
		return ;
	}
	ra_cnt = 0;
	while (chunk_size--)
	{
		if (max == a->top->item)
		{
			if (chunk_size)
			{
				ra(a);
				ra_cnt++;
			}
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

void	q_sort_r_3(t_stack *a, t_stack *b, int chunk_size)
{
	int	min;
	int	rb_cnt;

	min = ft_min(*b, chunk_size);
	if (b->top->next->next->item == min)
	{
		if (top(b) < b->top->next->item)
			sb(b);
		pa(a, b);
		pa(a, b);
		pa(a, b);
		return ;
	}
	rb_cnt = 0;
	while (chunk_size--)
	{
		if (min == top(b))
		{
			if (chunk_size)
			{
				rb(b);
				rb_cnt++;
			}
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

void	q_sort_5(t_stack *a, t_stack *b, int chunk_size)
{
	int	min1;
	int	min2;
	int	tmp;
	t_stack cur;

	min1 = ft_min(*b, chunk_size);
	if (chunk_size == 4)
	{
		while (chunk_size--)
		{
			if (min1 < top(b))
				pa(a, b);
			else
				rb(b);
		}
		rrb(b);
		q_sort_3(a, b, 3);
		pa(a, b);
		return ;
	}
	min2 = ft_max(*b, chunk_size);
	tmp = chunk_size;
	cur = *b;
	while (tmp--)
	{
		if (cur.top->item > min1 && min2 > cur.top->item)
			min2 = top(b);
		cur.top = cur.top->next;
	}
	while (chunk_size--)
	{
		if (min2 < top(b))
			pa(a, b);
		else
			rb(b);
	}
	rrb(b);
	rrb(b);
	if (top(b) < b->top->next->item)
		sb(b);
	q_sort_3(a, b, 3);
	pa(a, b);
	pa(a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min;
	int	mid;
	int	idx;
	int	pb_cnt;

	if (is_sorted(a, a->size))
		return ;
	pb_cnt = 0;
	while (a->size > 3)
	{
		mid = a->size / 2;
		min = ft_min(*a, a->size);
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

int	find_pivot(t_stack *a, t_stack *b, int st_name, int chunk_size)
{
	int 	max;
	int		min;
	int		mid;
	int		res;
	t_stack cur;

	if (st_name == 0)
	{
		max = ft_max(*a, chunk_size);
		min = ft_min(*a, chunk_size);
		cur = *a;
	}
	else
	{
		max = ft_max(*b, chunk_size);
		min = ft_min(*b, chunk_size);
		cur = *b;
	}
	mid = min + ((max - min) / 3);
	res = max;
	while (chunk_size--)
	{
		if (mid <= cur.top->item && res > cur.top->item)
			res = cur.top->item;
		cur.top = cur.top->next;
	}
	return (res);
}

int find_pivot2(t_stack *a, t_stack *b, int st_name, int chunk_size)
{
	int max;
	int min;
	int mid;
	int res;
	t_stack cur;

	if (st_name == 0)
	{
		max = ft_max(*a, chunk_size);
		min = ft_min(*a, chunk_size);
		cur = *a;
	}
	else
	{
		max = ft_max(*b, chunk_size);
		min = ft_min(*b, chunk_size);
		cur = *b;
	}
	mid = min + ((max - min) / 3 * 2);
	res = min;
	while (chunk_size--)
	{
		if (mid >= cur.top->item && res < cur.top->item)
			res = cur.top->item;
		cur.top = cur.top->next;
	}
	return (res);
}
