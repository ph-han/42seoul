/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:01:10 by phan              #+#    #+#             */
/*   Updated: 2023/05/20 13:13:53 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_stack *a)
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

void	sb(t_stack *b)
{
	sa(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
