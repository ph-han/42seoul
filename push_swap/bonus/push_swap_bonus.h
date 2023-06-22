/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:35:40 by phan              #+#    #+#             */
/*   Updated: 2023/06/22 11:51:45 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"

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
int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);
int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *a, t_stack *b);
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_stack *a, t_stack *b);
int		rra(t_stack *a);
int		rrb(t_stack *b);
int		rrr(t_stack *a, t_stack *b);

// utils
int		check_sorted(t_stack *a, t_stack *b, int chunk_size);
int		is_valid(t_stack st, char *s);
int		input_data(t_stack *a, int idx, char *argv[]);

#endif