/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:28:24 by phan              #+#    #+#             */
/*   Updated: 2023/06/21 17:19:33 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static void	reverse_rotate(t_stack *stack)
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
	idx--;
	while (idx > 0)
		push(tmp[--idx], stack);
	push(tmp[size - 1], stack);
	free(tmp);
	tmp = NULL;
}

int	rra(t_stack *a)
{
	reverse_rotate(a);
	return (1);
}

int	rrb(t_stack *b)
{
	reverse_rotate(b);
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return (1);
}
