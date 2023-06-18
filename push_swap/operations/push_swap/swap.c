/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:01:10 by phan              #+#    #+#             */
/*   Updated: 2023/06/18 14:23:43 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	ft_printf("sa\n");
	swap(a);
	return (1);
}

int	sb(t_stack *b)
{
	ft_printf("sb\n");
	swap(b);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
	return (1);
}
