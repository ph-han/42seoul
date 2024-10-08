/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:14:46 by phan              #+#    #+#             */
/*   Updated: 2023/01/29 15:41:59 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_ten_queens_puzzle(void);
int		is_valid_position(int board[], int idx);
void	board_print(int board[]);
void	solve_ten_queens(int idx, int board[], int *solve_count);

int	is_valid_position(int board[], int idx)
{
	int	i;

	i = 0;
	if (idx == 0)
		return (1);
	while (i < idx)
	{
		if (board[i] == board[idx])
			return (0);
		if (i - board[i] == idx - board[idx] || \
				i + board[i] == idx + board[idx])
			return (0);
		i++;
	}
	return (1);
}

void	board_print(int board[])
{
	char	temp;
	int		i;

	i = 0;
	while (i < 10)
	{
		temp = board[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	solve_ten_queens(int idx, int board[], int *solve_count)
{
	int	row_idx;

	row_idx = 0;
	if (idx == 10)
	{
		*solve_count += 1;
		board_print(board);
		return ;
	}
	while (row_idx < 10)
	{
		board[idx] = row_idx;
		if (is_valid_position(board, idx))
			solve_ten_queens(idx + 1, board, solve_count);
		row_idx++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	solve_count;
	int	ten_board[10];

	solve_count = 0;
	solve_ten_queens(0, ten_board, &solve_count);
	return (solve_count);
}
