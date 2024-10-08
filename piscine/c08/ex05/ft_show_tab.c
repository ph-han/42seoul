/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:50:32 by phan              #+#    #+#             */
/*   Updated: 2023/02/02 19:59:52 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

void	ft_show_tab(struct s_stock_str *par);

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

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (*(par + i)->str)
	{
		ft_putstr(par[i]->str);
		write(1, "\n", 1);
		ft_putnbr(par[i]->size);
		write(1, "\n", 1);
		ft_putstr(par[i]->copy);
		write(1, "\n", 1);
		i++;
	}
}
