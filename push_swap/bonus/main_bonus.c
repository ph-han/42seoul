/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:34:06 by phan              #+#    #+#             */
/*   Updated: 2023/06/21 17:20:52 by phan             ###   ########.fr       */
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

static int	input_data_free_all(char **inputs)
{
	int	idx;

	idx = 0;
	while (inputs[idx])
		free(inputs[idx++]);
	free(inputs);
	return (-1);
}

static int	input_data(t_stack *a, int idx, char *argv[])
{
	char	**inputs;
	int		input_num;

	while (idx > 0)
	{
		inputs = ft_split(argv[idx], ' ');
		input_num = 0;
		while (inputs[input_num])
			input_num++;
		if (input_num == 0)
		{
			free(inputs);
			return (-1);
		}
		while (input_num)
		{
			if (!is_valid(*a, inputs[--input_num]))
				return (input_data_free_all(inputs));
			push(ft_atoi(inputs[input_num]), a);
		}
		input_data_free_all(inputs);
		idx--;
	}
	return (1);
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

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	*line;

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
	line = get_next_line(0);
	while (line)
	{
		if (run_command(line, &a, &b) == 0)
		{
			free(line);
			free_all(&a);
			free_all(&b);
			return ((write(2, "Error\n", 6) * 0) + -1);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (check_sorted(&a, &b, a.size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&a);
	free_all(&b);
	return (0);
}
