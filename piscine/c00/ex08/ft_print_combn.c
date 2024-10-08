/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:05:20 by phan              #+#    #+#             */
/*   Updated: 2023/01/19 10:53:44 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	ft_print(int nb[], int n);
void	ft_init(int nb[], int n);

void	ft_print_combn(int n)
{
	int	i;
	int	nb[10];

	ft_init(nb, n);
	i = n - 1;
	while (i >= 0)
	{
		while (nb[i] == 10 - n + i)
			i--;
		ft_print(nb, n);
		if (nb[0] == 10 - n)
			break ;
		if (nb[i] < 10 - n + i)
			nb[i]++;
		if (i < n - 1 && nb[i + 1] == 11 - n + i)
		{
			while (i < n - 1)
			{
				nb[i + 1] = nb[i] + 1;
				i++;
			}
		}
	}
}

void	ft_init(int nb[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		nb[i] = i;
		i++;
	}
}

void	ft_print(int nb[], int n)
{
	int		i;
	char	temp;

	i = 0;
	while (i < n)
	{
		temp = nb[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	if (nb[0] != 10 - n)
		write(1, ", ", 2);
}
