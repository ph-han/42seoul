/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:54:42 by phan              #+#    #+#             */
/*   Updated: 2023/04/01 17:43:02 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(long long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	tmp_n;
	size_t		n_len;
	size_t		idx;

	tmp_n = n;
	n_len = numlen(tmp_n);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (0);
	if (tmp_n < 0)
	{
		str[0] = '-';
		tmp_n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	str[n_len] = '\0';
	idx = n_len - 1;
	while (tmp_n)
	{
		str[idx--] = (tmp_n % 10) + '0';
		tmp_n /= 10;
	}
	return (str);
}
