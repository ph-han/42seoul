/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:17:31 by phan              #+#    #+#             */
/*   Updated: 2023/04/01 14:53:12 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long long	tmp;

	tmp = n;
	if (tmp < 0)
	{
		write(fd, "-", 1);
		tmp *= -1;
	}
	if (!tmp)
	{
		write(fd, "0", 1);
		return ;
	}
	if (!(tmp / 10))
	{
		c = (tmp % 10) + '0';
		write(fd, &c, 1);
		return ;
	}
	ft_putnbr_fd(tmp / 10, fd);
	c = (tmp % 10) + '0';
	write(fd, &c, 1);
}
