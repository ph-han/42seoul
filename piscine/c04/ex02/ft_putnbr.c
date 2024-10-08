/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:35:00 by phan              #+#    #+#             */
/*   Updated: 2023/01/28 10:25:05 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putnbr(int nb)
{
	char	temp[11];
	int		size;

	size = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (nb != 0)
	{
		temp[10 - size] = nb % 10 + '0';
		nb /= 10;
		size++;
	}
	write(1, (temp + 11 - size), size);
}
