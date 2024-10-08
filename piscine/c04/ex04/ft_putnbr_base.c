/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:15:41 by phan              #+#    #+#             */
/*   Updated: 2023/01/28 19:49:52 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
void	print(long long nbr, int size, char *base);
int		is_valid_base(char *base, int size);

void	print(long long nbr, int size, char *base)
{
	char	temp;

	if (nbr == 0)
		return ;
	print(nbr / size, size, base);
	temp = base[nbr % size];
	write(1, &temp, 1);
}

int	is_valid_base(char *base, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size == 0 || size == 1)
		return (0);
	while (i < size)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			size;
	long long	num;

	size = 0;
	num = (long long)nbr;
	while (*(base + size))
		size++;
	if (!is_valid_base(base, size))
		return ;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num == 0)
	{
		write(1, base, 1);
		return ;
	}
	print(num, size, base);
}
