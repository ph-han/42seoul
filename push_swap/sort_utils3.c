/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:07:57 by phan              #+#    #+#             */
/*   Updated: 2023/06/18 17:32:33 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	restore_a(t_stack *a, t_cnt_op *cnt)
{
	if (cnt->a_not_mv_cnt > cnt->ra_cnt)
		while (cnt->ra_cnt_tmp--)
			rra(a);
	else
		while (cnt->a_not_mv_cnt--)
			ra(a);
}

static void	restore_b(t_stack *b, t_cnt_op *cnt)
{
	if (cnt->b_not_mv_cnt > cnt->rb_cnt)
		while (cnt->rb_cnt_tmp--)
			rrb(b);
	else
		while (cnt->b_not_mv_cnt--)
			rb(b);
}

void	restore_stack(t_stack *a, t_stack *b, t_cnt_op *cnt)
{
	cnt->a_not_mv_cnt = a->size - cnt->ra_cnt;
	cnt->b_not_mv_cnt = b->size - cnt->rb_cnt;
	cnt->rb_cnt_tmp = cnt->rb_cnt;
	cnt->ra_cnt_tmp = cnt->ra_cnt;
	while (cnt->ra_cnt_tmp && cnt->rb_cnt_tmp)
	{
		rrr(a, b);
		cnt->ra_cnt_tmp--;
		cnt->rb_cnt_tmp--;
	}
	if (cnt->ra_cnt_tmp == cnt->ra_cnt)
		restore_a(a, cnt);
	else
		while (cnt->a_not_mv_cnt && cnt->ra_cnt_tmp--)
			rra(a);
	if (cnt->rb_cnt_tmp == cnt->rb_cnt)
		restore_b(a, cnt);
	else
		while (cnt->b_not_mv_cnt && cnt->rb_cnt_tmp--)
			rrb(b);
}
