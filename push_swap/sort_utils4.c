/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:09:27 by phan              #+#    #+#             */
/*   Updated: 2023/06/18 17:58:35 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partioning_a(t_stack *a, t_stack *b, t_pivot pivot, t_cnt_op *cnt)
{
	if (pivot.two_thirds <= top(a))
		cnt->ra_cnt += ra(a);
	else
	{
		cnt->pb_cnt += pb(a, b);
		if (top(b) >= pivot.one_third)
			cnt->rb_cnt += rb(b);
	}
}

void	partioning_b(t_stack *a, t_stack *b, t_pivot pivot, t_cnt_op *cnt)
{
	if (pivot.one_third > top(b))
		cnt->rb_cnt += rb(b);
	else
	{
		cnt->pa_cnt += pa(a, b);
		if (pivot.two_thirds > top(a))
			cnt->ra_cnt += ra(a);
	}
}
