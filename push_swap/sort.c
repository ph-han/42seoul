/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:08:03 by phan              #+#    #+#             */
/*   Updated: 2023/06/18 17:58:27 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	init_s(t_cnt_op *s)
{
	s->pa_cnt = 0;
	s->pb_cnt = 0;
	s->ra_cnt = 0;
	s->rb_cnt = 0;
	s->rb_cnt = 0;
	s->ra_cnt_tmp = 0;
	s->rb_cnt_tmp = 0;
	s->a_not_mv_cnt = 0;
	s->b_not_mv_cnt = 0;
}

void	sort_start(t_stack *a, t_stack *b, int chunk_size)
{
	t_pivot		pivot;
	t_cnt_op	cnt;

	pivot.one_third = find_pivot(a, b, 'a', chunk_size);
	pivot.two_thirds = find_pivot2(a, b, 'a', chunk_size);
	init_s(&cnt);
	while (chunk_size--)
	{
		if (pivot.two_thirds <= top(a))
			cnt.ra_cnt += ra(a);
		else
		{
			pb(a, b);
			if (top(b) >= pivot.one_third)
				cnt.rb_cnt++;
			else
				rb(b);
			cnt.pb_cnt++;
		}
	}
	if (is_sorted(a, cnt.ra_cnt) == 0)
		sort_a(a, b, cnt.ra_cnt);
	sort_b(a, b, cnt.rb_cnt);
	sort_b(a, b, cnt.pb_cnt - cnt.rb_cnt);
}

void	sort_a(t_stack *a, t_stack *b, int chunk_size)
{
	t_pivot		pivot;
	t_cnt_op	cnt;

	if (chunk_size <= 3)
	{
		under_3_a(a, b, chunk_size);
		return ;
	}
	pivot.one_third = find_pivot(a, b, 'a', chunk_size);
	pivot.two_thirds = find_pivot2(a, b, 'a', chunk_size);
	init_s(&cnt);
	while (chunk_size--)
		partioning_a(a, b, pivot, &cnt);
	restore_stack(a, b, &cnt);
	if (is_sorted(a, cnt.ra_cnt) == 0)
		sort_a(a, b, cnt.ra_cnt);
	sort_b(a, b, cnt.rb_cnt);
	sort_b(a, b, cnt.pb_cnt - cnt.rb_cnt);
}

void	sort_b(t_stack *a, t_stack *b, int chunk_size)
{
	t_pivot		pivot;
	t_cnt_op	cnt;

	if (chunk_size <= 3)
	{
		under_3_b(a, b, chunk_size);
		return ;
	}
	pivot.one_third = find_pivot(a, b, 'b', chunk_size);
	pivot.two_thirds = find_pivot2(a, b, 'b', chunk_size);
	init_s(&cnt);
	while (chunk_size--)
		partioning_b(a, b, pivot, &cnt);
	if (is_sorted(a, cnt.pa_cnt - cnt.ra_cnt) == 0)
		sort_a(a, b, cnt.pa_cnt - cnt.ra_cnt);
	restore_stack(a, b, &cnt);
	if (is_sorted(a, cnt.ra_cnt) == 0)
		sort_a(a, b, cnt.ra_cnt);
	sort_b(a, b, cnt.rb_cnt);
}

void	quick_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a, a->size))
		return ;
	sort_start(a, b, a->size);
}
