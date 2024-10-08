/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byojeon <byojeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:14:20 by byojeon           #+#    #+#             */
/*   Updated: 2023/01/14 17:11:51 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	print_horizon(int n, char letter);
void	print_vertical(int n, int m);
void	rush(int x, int y);

void	print_point(int n, char letter)
{
	ft_putchar(letter);
	if (n >= 0)
	{
		print_horizon(n, 'B');
		ft_putchar(letter);
	}
}

void	print_horizon(int n, char letter)
{
	while (n > 0)
	{
		ft_putchar(letter);
		n--;
	}
}

void	print_vertical(int n, int m)
{
	ft_putchar('\n');
	while (m > 0)
	{
		ft_putchar('B');
		if (n >= 0)
		{
			print_horizon(n, ' ');
			ft_putchar('B');
		}
		ft_putchar('\n');
		m--;
	}
}

void	rush(int x, int y)
{
	int	n;
	int	m;

	n = x - 2;
	m = y - 2;
	if (x <= 0 || y <= 0)
	{
		write(1, "Invalid Number\n", 15);
		return ;
	}
	print_point(n, 'A');
	if (y >= 2)
	{
		print_vertical(n, m);
		print_point(n, 'C');
	}
	ft_putchar('\n');
}
