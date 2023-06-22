/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:08:20 by phan              #+#    #+#             */
/*   Updated: 2023/06/22 11:48:38 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	pa(t_stack *a, t_stack *b)
{
	if (b->size < 1)
		return (1);
	ft_printf("pa\n");
	push(pop(b), a);
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	if (a->size < 1)
		return (1);
	ft_printf("pb\n");
	push(pop(a), b);
	return (1);
}
