/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:01:10 by phan              #+#    #+#             */
/*   Updated: 2023/06/21 16:18:42 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static void	swap(t_stack *a)
{
	int	item1;
	int	item2;

	if (a->size <= 1)
		return ;
	item1 = pop(a);
	item2 = pop(a);
	push(item1, a);
	push(item2, a);
}

int	sa(t_stack *a)
{
	swap(a);
	return (1);
}

int	sb(t_stack *b)
{
	swap(b);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	return (1);
}
