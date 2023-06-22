/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:41:53 by phan              #+#    #+#             */
/*   Updated: 2023/06/22 11:51:20 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./lib/libft/libft.h"
# include "./lib/printf/ft_printf.h"

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

typedef struct s_cnt_op
{
	int	pa_cnt;
	int	pb_cnt;
	int	ra_cnt;
	int	rb_cnt;
	int	ra_cnt_tmp;
	int	rb_cnt_tmp;
	int	a_not_mv_cnt;
	int	b_not_mv_cnt;
}	t_cnt_op;

typedef struct s_pivot
{
	int	one_third;
	int	two_thirds;
}	t_pivot;

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

// mini sort functions
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);

// quick sort functions 
void	q_sort_3_a(t_stack *a, t_stack *b, int chunk_size, int ra_cnt);
void	q_sort_3_b(t_stack *a, t_stack *b, int chunk_size, int rb_cnt);
void	sort_a(t_stack *a, t_stack *b, int chunk_size);
void	sort_b(t_stack *a, t_stack *b, int chunk_size);
void	sort_start(t_stack *a, t_stack *b, int chunk_size);
void	restore_stack(t_stack *a, t_stack *b, t_cnt_op *cnt);
void	quick_sort(t_stack *a, t_stack *b);
void	partioning_a(t_stack *a, t_stack *b, t_pivot pivot, t_cnt_op *cnt);
void	partioning_b(t_stack *a, t_stack *b, t_pivot pivot, t_cnt_op *cnt);
void	under_3_b(t_stack *a, t_stack *b, int chunk_size);
void	under_3_a(t_stack *a, t_stack *b, int chunk_size);
int		find_pivot(t_stack *a, t_stack *b, char st_name, int chunk_size);
int		find_pivot2(t_stack *a, t_stack *b, char st_name, int chunk_size);
int		is_sorted(t_stack *st, int chunk_size);

// utils functions
int		ft_max(t_stack st, int chunk_size);
int		ft_min(t_stack st, int chunk_size);
int		ft_find(t_stack st, int item);
int		ft_is_valid(t_stack st, char *s);

#endif
