/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:34:06 by phan              #+#    #+#             */
/*   Updated: 2023/06/22 11:40:48 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	free_all(t_stack *st)
{
	t_node	*tmp;

	while (st->top)
	{
		tmp = st->top;
		st->top = st->top->next;
		free(tmp);
	}
}

static int	run_command(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strncmp(cmd, "sa\n", ft_strlen(cmd)) == 0)
		sa(a);
	else if ((ft_strncmp(cmd, "sb\n", ft_strlen(cmd)) == 0))
		sb(b);
	else if ((ft_strncmp(cmd, "ss\n", ft_strlen(cmd)) == 0))
		ss(a, b);
	else if ((ft_strncmp(cmd, "pb\n", ft_strlen(cmd)) == 0))
		pb(a, b);
	else if ((ft_strncmp(cmd, "pa\n", ft_strlen(cmd)) == 0))
		pa(a, b);
	else if ((ft_strncmp(cmd, "ra\n", ft_strlen(cmd)) == 0))
		ra(a);
	else if ((ft_strncmp(cmd, "rra\n", ft_strlen(cmd)) == 0))
		rra(a);
	else if ((ft_strncmp(cmd, "rb\n", ft_strlen(cmd)) == 0))
		rb(b);
	else if ((ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)) == 0))
		rrb(b);
	else if ((ft_strncmp(cmd, "rr\n", ft_strlen(cmd)) == 0))
		rr(a, b);
	else if ((ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)) == 0))
		rrr(a, b);
	else
		return (0);
	return (1);
}

static int	read_command(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (run_command(line, a, b) == 0)
		{
			free(line);
			free_all(a);
			free_all(b);
			return ((write(2, "Error\n", 6) * 0) + -1);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	init(&a);
	if (argc < 2)
		return (-1);
	if (input_data(&a, argc - 1, argv) == -1)
	{
		if (a.top)
			free_all(&a);
		return ((write(2, "Error\n", 6) * 0) + -1);
	}
	init(&b);
	if (read_command(&a, &b) < 0)
		return (-1);
	if (check_sorted(&a, &b, a.size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&a);
	free_all(&b);
	return (0);
}
