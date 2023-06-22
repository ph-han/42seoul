/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:18:46 by phan              #+#    #+#             */
/*   Updated: 2023/06/22 11:48:52 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push(int item, t_stack *stack)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->item = item;
	new->idx = stack->size;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*tmp;
	int		item;

	tmp = stack->top;
	item = tmp->item;
	stack->top = tmp->next;
	free(tmp);
	stack->size--;
	return (item);
}

int	top(t_stack *stack)
{
	int	item;

	item = stack->top->item;
	return (item);
}

int	is_empty(t_stack *stack)
{
	if (stack->size == 0)
		return (1);
	return (0);
}

void	init(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}
