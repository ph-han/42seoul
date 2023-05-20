/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:12:28 by phan              #+#    #+#             */
/*   Updated: 2023/05/20 13:26:55 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_stack *a)
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
	push(tmp[0], a);
	while ((idx - 1) > 0)
		push(tmp[--idx], a);
	free(tmp);
	tmp = NULL;
}

void	rb(t_stack *b)
{
	ra(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
