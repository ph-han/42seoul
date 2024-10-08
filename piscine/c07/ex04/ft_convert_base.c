/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:40:34 by phan              #+#    #+#             */
/*   Updated: 2023/02/01 20:37:22 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_atoi_base(char *str, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		get_nbr_len(long long nbr, int base_to_len);
int		str_len(char *str);
char	*fill_result(long long nbr, char *result, char *base_to, int rsize);

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

int	get_nbr_len(long long nbr, int base_to_len)
{
	int	len;

	if (nbr < 0)
	{
		len = 1;
		nbr *= -1;
	}
	else
		len = 0;
	while (nbr != 0)
	{
		nbr /= base_to_len;
		len++;
	}
	return (len);
}

char	*fill_result(long long nbr, char *result, char *base_to, int rsize)
{
	int	idx;
	int	base_size;

	idx = 2;
	base_size = str_len(base_to);
	while (nbr != 0)
	{
		result[rsize - idx] = base_to[nbr % base_size];
		nbr /= base_size;
		idx++;
	}
	result[rsize - 1] = '\0';
	return (result);
}

int	is_valid_base(char *base, int size, int is_from)
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
		if (is_from && ((base[i] >= 9 && base[i] <= 13) || base[i] == 32))
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*result;
	long long	num;
	int			base_to_len;
	int			base_from_len;
	int			result_size;

	base_to_len = str_len(base_to);
	base_from_len = str_len(base_from);
	if (!is_valid_base(base_to, base_to_len, 0) || \
			!is_valid_base(base_from, base_from_len, 1))
		return (0);
	num = (long long)ft_atoi_base(nbr, base_from);
	result_size = get_nbr_len(num, base_to_len) + 1;
	result = (char *)malloc(result_size);
	if (num < 0)
	{
		num *= -1;
		result[0] = '-';
	}
	if (num == 0)
		result[0] = base_to[0];
	else
		result = fill_result(num, result, base_to, result_size);
	return (result);
}
