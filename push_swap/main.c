/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanpilho <hanpilho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:39:13 by phan              #+#    #+#             */
/*   Updated: 2023/05/28 16:55:19 by hanpilho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_swap(t_stack *a, t_stack *b)
{
	t_stack pivot;
	t_stack curr;

	init(&pivot);
	if (a->size <= 3)
	{
		sort_3_under_items(a);
		return;
	}
	push(a->top->item, &pivot);
	curr = *a;
	while (curr.top)
	{
		if (pivot.top->item < curr.top->item)
			ra(a);
		else
			pb(a, b);
		curr.top = curr.top->next;
	}
	if (a->size > 3)
		push_swap(a, b);
	else
		sort_3_under_items(a);
	sort(a, b, &pivot);
	return;
}

// static int	is_valid(char *item)
// {

// }

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;
	int idx;

	init(&a);
	init(&b);
	if (argc < 2)
		return ((ft_printf("Error\n") * 0) + -1);
	idx = argc - 1;
	while (idx > 0)
	{
		// if (is_valid(argv[idx]) == 0)
		// return ((ft_printf("Error\n") * 0) + -1);
		push(ft_atoi(argv[idx]), &a);
		idx--;
	}
	push_swap(&a, &b);
	return (0);
}
