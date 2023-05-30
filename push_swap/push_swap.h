/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:41:53 by phan              #+#    #+#             */
/*   Updated: 2023/05/30 16:07:23 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./includes/libft/libft.h"
# include "./includes/printf/ft_printf.h"

typedef struct s_node
{
	int				item;
	int				idx;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// stack operations
void	init(t_stack *stack);
void	push(int item, t_stack *stack);
int		pop(t_stack *stack);
int		top(t_stack *stack);
int		is_empty(t_stack *stack);

// push_swap operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// sort functions
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);

// utils functions
int		ft_max(t_stack st);
int		ft_min(t_stack st);
int		ft_find(t_stack st, int item);
int		ft_is_valid(t_stack st, char *s);

#endif