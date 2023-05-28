/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanpilho <hanpilho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:08:48 by hanpilho          #+#    #+#             */
/*   Updated: 2023/05/28 19:10:33 by hanpilho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3_under_items(t_stack *a)
{
    int max;

    if (a->size < 2)
        return;
    max = find_max(*a);
    if (a->top->item == max)
        ra(a);
    if (a->top->next->next)
    {
        if (a->top->next->item > a->top->next->next->item)
            rra(a);
        if (a->top->item > a->top->next->item)
            sa(a);
    }
}

void sort_desc_3_under_items(t_stack *a)
{
    int max;

    if (a->size < 2)
        return;
    max = find_max(*a);
    if (a->top->item < max)
        ra(a);
    if (a->top->next->next)
    {
        if (a->top->next->item < a->top->next->next->item)
            rra(a);
        if (a->top->item < a->top->next->item)
            sa(a);
    }
}
