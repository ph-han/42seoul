/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanpilho <hanpilho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:08:54 by hanpilho          #+#    #+#             */
/*   Updated: 2023/05/28 19:09:29 by hanpilho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack st, char c)
{
    ft_printf("%c : ", c);
    while (st.top)
    {
        ft_printf("%d ", st.top->item);
        st.top = st.top->next;
    }
    ft_printf("\n");
}

int find_max(t_stack st)
{
    int max;

    max = st.top->item;
    while (st.top)
    {
        if (max < st.top->item)
            max = st.top->item;
        st.top = st.top->next;
    }
    return (max);
}