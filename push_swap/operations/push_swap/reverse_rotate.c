/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:28:24 by phan              #+#    #+#             */
/*   Updated: 2023/05/20 13:32:27 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_stack *a)
{
	int	size;
	int	*tmp;
	int	idx;

	if (a->size <= 1)
		return ;
	size = a->size;
	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return ;
	idx = 0;
	while (!a->size)
		tmp[idx++] = pop(a);
	idx--;
	while (idx > 0)
		push(tmp[--idx], a);
	push(tmp[size - 1], a);
	free(tmp);
	tmp = NULL;
}

void	rrb(t_stack *b)
{
	rra(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
