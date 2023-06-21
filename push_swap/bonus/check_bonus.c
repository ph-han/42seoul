/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:57:40 by phan              #+#    #+#             */
/*   Updated: 2023/06/21 17:20:00 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	check_sorted(t_stack *a, t_stack *b, int chunk_size)
{
	t_stack	cur;

	if (b->size > 0)
		return (0);
	cur = *a;
	while (chunk_size-- && cur.top->next)
	{
		if (cur.top->item > cur.top->next->item)
			return (0);
		cur.top = cur.top->next;
	}
	return (1);
}
