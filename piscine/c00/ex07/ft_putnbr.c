/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:26:21 by phan              #+#    #+#             */
/*   Updated: 2023/01/17 18:39:28 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_count(int n);
int		ft_power(int n);
void	ft_putnbr(int nb);

void	ft_putnbr(int nb)
{
	int		i;
	char	temp_n;

	i = ft_count(nb) - 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (i >= 0)
	{
		temp_n = (nb / ft_power(i)) + '0';
		nb %= ft_power(i);
		write(1, &temp_n, 1);
		i--;
	}
}

int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_power(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result *= 10;
		n--;
	}
	return (result);
}
