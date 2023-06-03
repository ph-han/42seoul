/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:08:03 by phan              #+#    #+#             */
/*   Updated: 2023/06/03 21:38:22 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack *a, t_stack *b, int chunk_size)
{
	int 	pivot;
	int		pb_cnt = 0;
	int		ra_cnt = 0;
	int		ra_cnt_tmp;
	int		not_mv;

	// ft_printf("=======(sort_a start, chunk_size : %d)======\n", chunk_size);
	if (chunk_size <= 1)
	{
		// print_stack(*a, 'a');
		// print_stack(*b, 'b');
		return ;
	}
	pivot = top(a);
	while (chunk_size--)
	{
		if (pivot < a->top->item)
		{
			ra(a);
			ra_cnt++;
		}
		else
		{
			pb(a, b);
			if (b->size > 1 && b->top->item == pivot)
				rb(b);
			pb_cnt++;
		}
	}
	rrb(b);
	not_mv = a->size - ra_cnt;
	ra_cnt_tmp = ra_cnt;
	// ft_printf("sorta -> not_mv : %d, ra_cnt: %d", not_mv, ra_cnt);
	if (not_mv > ra_cnt)
		while (ra_cnt_tmp--)
			rra(a);
	else
		while (not_mv--)
			ra(a);
	// print_stack(*a, 'a');
	// print_stack(*b, 'b');
	sort_a(a, b, ra_cnt);
	sort_b(a, b, pb_cnt);
	// ft_printf("=======(sort_a end)======\n");
}

void	sort_b(t_stack *a, t_stack *b, int chunk_size)
{
	int		pivot;
	int		pa_cnt = 0;
	int		rb_cnt = 0;
	int		rb_cnt_tmp;
	int		not_mv;

	// ft_printf("=======(sort_b start, chunk_size : %d)======\n", chunk_size);
	if (chunk_size == 0)
		return ;
	if (chunk_size <= 1)
	{
		pa(a, b);
	 	// print_stack(*a, 'a');
		// print_stack(*b, 'b');
		return ;
	}
	pivot = b->top->next->item;
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
		}
	}
	// rb_cnt_tmp = rb_cnt;
	not_mv = b->size - rb_cnt;
	rb_cnt_tmp = rb_cnt;
	// ft_printf("sortb -> not_mv : %d, rb_cnt: %d", not_mv, rb_cnt);
	if (not_mv > rb_cnt)
		while (rb_cnt_tmp--)
			rrb(b);
	else
		while (not_mv--)
			rb(b);
	// print_stack(*a, 'a');
	// print_stack(*b, 'b');
	sort_a(a, b, pa_cnt);
	sort_b(a, b, rb_cnt);
	// ft_printf("=======(sort_b end)=======\n");
}

void	quick_sort(t_stack *a, t_stack *b)
{
	sort_a(a, b, a->size);
}
