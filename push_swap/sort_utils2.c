/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:51:14 by phan              #+#    #+#             */
/*   Updated: 2023/06/18 20:43:51 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	init_value(t_stack *st, int *max, int *min, int chunk_size)
{
	*max = ft_max(*st, chunk_size);
	*min = ft_min(*st, chunk_size);
	return (*st);
}

int	find_pivot(t_stack *a, t_stack *b, char st_name, int chunk_size)
{
	int		max;
	int		min;
	int		pos;
	int		res;
	t_stack	cur;

	if (st_name == 'a')
		cur = init_value(a, &max, &min, chunk_size);
	else
		cur = init_value(b, &max, &min, chunk_size);
	pos = min + ((max - min) / 3);
	res = min;
	while (chunk_size--)
	{
		if (pos >= cur.top->item && res < cur.top->item)
			res = cur.top->item;
		cur.top = cur.top->next;
	}
	// ft_printf("======Pivot1: %d\n======", res);
	return (res);
}

int	find_pivot2(t_stack *a, t_stack *b, char st_name, int chunk_size)
{
	int		max;
	int		min;
	int		pos;
	int		res;
	t_stack	cur;

	if (st_name == 'a')
		cur = init_value(a, &max, &min, chunk_size);
	else
		cur = init_value(b, &max, &min, chunk_size);
	pos = min + ((max - min) / 3 * 2);
	res = max;
	while (chunk_size--)
	{
		if (pos <= cur.top->item && res > cur.top->item)
			res = cur.top->item;
		cur.top = cur.top->next;
	}
	// ft_printf("=====Pivot2 : %d====\n", res);
	return (res);
}
