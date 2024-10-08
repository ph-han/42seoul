/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:40:43 by phan              #+#    #+#             */
/*   Updated: 2023/01/15 18:21:15 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	print_numbers(int n, int m);

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 < 99)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			print_numbers(num1, num2);
			num2++;
		}
		num1++;
	}
}

void	print_numbers(int n, int m)
{
	char	n1;
	char	n2;
	char	m1;
	char	m2;

	n1 = (n / 10) + '0';
	n2 = (n % 10) + '0';
	m1 = (m / 10) + '0';
	m2 = (m % 10) + '0';
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, " ", 1);
	write(1, &m1, 1);
	write(1, &m2, 1);
	if (n != 98 || m != 99)
		write(1, ", ", 2);
}
