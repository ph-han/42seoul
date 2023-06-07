/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:08:03 by phan              #+#    #+#             */
/*   Updated: 2023/06/07 15:10:53 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a, int b)
{
	return ((a < b)*-1*(a - b) + (a >= b)*(a - b));
}

void	sort_a(t_stack *a, t_stack *b, int chunk_size)
{
	int	pivot;
	int	pivot2;
	int	pb_cnt;
	int	ra_cnt;
	int	rb_cnt;
	int	ra_cnt_tmp;
	int	rb_cnt_tmp;
	int	a_not_mv;
	int	b_not_mv;
// 
	// ft_printf("=======(sort_a start, chunk_size : %d)======\n", chunk_size);
	if (chunk_size <= 1)
		return ;
	if (chunk_size == 2)
	{
		if (top(a) > a->top->next->item)
			sa(a);
		return ;
	}
	if (chunk_size == 3)
	{
		q_sort_3(a, b, chunk_size);
		return ;
	}
	pivot = find_pivot(a, b, 0, chunk_size);
	pivot2 = find_pivot2(a, b, 0, chunk_size);
	// ft_printf("pivot : %d , pivot2 : %d\n", pivot, pivot2);
	pb_cnt = 0;
	ra_cnt = 0;
	rb_cnt = 0;
	while (chunk_size--)
	{
		if (pivot2 <= top(a))
		{
			ra(a);
			ra_cnt++;
		}
		else
		{
			pb(a, b);
			if (top(b) >= pivot)
			{
				if (b->top->next && top(b) > b->top->next->item)
					rb(b);
				rb_cnt++;
			}
			pb_cnt++;
		}
	}
	a_not_mv = a->size - ra_cnt;
	b_not_mv = b->size - rb_cnt;
	rb_cnt_tmp = rb_cnt;
	ra_cnt_tmp = ra_cnt;
	while (ra_cnt_tmp && rb_cnt_tmp)
	{
		rrr(a, b);
		ra_cnt_tmp--;
		rb_cnt_tmp--;
	}
	if (ra_cnt_tmp == ra_cnt)
	{
		if (a_not_mv > ra_cnt)
			while (ra_cnt_tmp--)
				rra(a);
		else
			while (a_not_mv--)
				ra(a);
	}
	else
	{
		while (a_not_mv && ra_cnt_tmp--)
			rra(a);
	}
	if (rb_cnt_tmp == rb_cnt)
	{
		if (b_not_mv > rb_cnt)
			while (rb_cnt_tmp--)
				rrb(b);
		else
			while (b_not_mv--)
				rb(b);
	}
	else
	{
		while (b_not_mv && rb_cnt_tmp--)
			rrb(b);
	}
	// print_stack(*a, 'a');
	// print_stack(*b, 'b');
	if (is_sorted(a, ra_cnt) == 0)
		sort_a(a, b, ra_cnt);
	sort_b(a, b, rb_cnt);
	sort_b(a, b, pb_cnt - rb_cnt);
	// ft_printf("=======(sort_a end)======\n");
}

void	sort_b(t_stack *a, t_stack *b, int chunk_size)
{
	int		pivot;
	int		pivot2;
	int		pa_cnt;
	int		rb_cnt;
	int		ra_cnt;
	int		rb_cnt_tmp;
	int		ra_cnt_tmp;
	int		a_not_mv;
	int		b_not_mv;
	//int		not_mv;

	// ft_printf("=======(sort_b start, chunk_size : %d)======\n", chunk_size);
	if (chunk_size == 0)
		return ;
	if (chunk_size == 2)
	{
		if (top(b) < b->top->next->item)
			sb(b);
		pa(a, b);
		pa(a, b);
		return ;
	}
	if (chunk_size == 3)
	{
		q_sort_r_3(a, b, chunk_size);
		return ;
	}
	if (chunk_size == 1)
	{
		pa(a, b);
		return ;
	}
	pivot = find_pivot(a, b, 1, chunk_size);
	pivot2 = find_pivot2(a, b, 1, chunk_size);
	// ft_printf("pivot : %d , pivot2 : %d\n", pivot, pivot2);
	pa_cnt = 0;
	rb_cnt = 0;
	ra_cnt = 0;
	while (chunk_size--)
	{
		if (pivot > top(b))
		{
			rb(b);
			rb_cnt++;
		}
		else
		{
			pa(a, b);
			pa_cnt++;
			if (pivot2 > top(a))
			{
				ra(a);
				ra_cnt++;
			}
		}
	}
	// not_mv = b->size - rb_cnt;
	a_not_mv = a->size - ra_cnt;
	b_not_mv = b->size - rb_cnt;
	rb_cnt_tmp = rb_cnt;
	ra_cnt_tmp = ra_cnt;
	// print_stack(*a, 'a');
	// print_stack(*b, 'b');
	if (is_sorted(a, pa_cnt - ra_cnt) == 0)
		sort_a(a, b, pa_cnt - ra_cnt);
	while (ra_cnt_tmp && rb_cnt_tmp)
	{
		rrr(a, b);
		ra_cnt_tmp--;
		rb_cnt_tmp--;
	}
	if (ra_cnt_tmp == ra_cnt)
	{
		if (a_not_mv > ra_cnt)
			while (ra_cnt_tmp--)
				rra(a);
		else
			while (a_not_mv--)
				ra(a);
	}
	else
	{
		while (a_not_mv && ra_cnt_tmp--)
			rra(a);
	}
	if (rb_cnt_tmp == rb_cnt)
	{
		if (b_not_mv > rb_cnt)
			while (rb_cnt_tmp--)
				rrb(b);
		else
			while (b_not_mv--)
				rb(b);
	}
	else
	{
		while (b_not_mv && rb_cnt_tmp--)
			rrb(b);
	}
	if (is_sorted(a, ra_cnt) == 0)
		sort_a(a, b, ra_cnt);
	sort_b(a, b, rb_cnt);
	// ft_printf("=======(sort_b end)=======\n");
}

void	quick_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a, a->size))
		return ;
	sort_a(a, b, a->size);
}
