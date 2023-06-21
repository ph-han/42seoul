/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:08:20 by phan              #+#    #+#             */
/*   Updated: 2023/06/21 16:19:27 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	pa(t_stack *a, t_stack *b)
{
	if (b->size < 1)
		return (1);
	push(pop(b), a);
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	if (a->size < 1)
		return (1);
	push(pop(a), b);
	return (1);
}
