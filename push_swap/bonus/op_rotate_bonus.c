/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:12:28 by phan              #+#    #+#             */
/*   Updated: 2023/06/21 16:20:04 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static void	rotate(t_stack *stack)
{
	int	size;
	int	*tmp;
	int	idx;

	if (stack->size <= 1)
		return ;
	size = stack->size;
	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return ;
	idx = 0;
	while (stack->size)
		tmp[idx++] = pop(stack);
	push(tmp[0], stack);
	while ((idx - 1) > 0)
		push(tmp[--idx], stack);
	free(tmp);
	tmp = NULL;
}

int	ra(t_stack *a)
{
	rotate(a);
	return (1);
}

int	rb(t_stack *b)
{
	rotate(b);
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	return (1);
}
