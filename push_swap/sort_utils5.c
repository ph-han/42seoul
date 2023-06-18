/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:11:46 by phan              #+#    #+#             */
/*   Updated: 2023/06/18 17:33:53 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	under_3_a(t_stack *a, t_stack *b, int chunk_size)
{
	if (chunk_size <= 1)
		return ;
	if (chunk_size == 2)
	{
		if (top(a) > a->top->next->item)
			sa(a);
		return ;
	}
	q_sort_3_a(a, b, chunk_size, 0);
}

void	under_3_b(t_stack *a, t_stack *b, int chunk_size)
{
	if (chunk_size == 0)
		return ;
	if (chunk_size == 1)
	{
		pa(a, b);
		return ;
	}
	if (chunk_size == 2)
	{
		if (top(b) < b->top->next->item)
			sb(b);
		pa(a, b);
		pa(a, b);
		return ;
	}
	q_sort_3_b(a, b, chunk_size, 0);
}
