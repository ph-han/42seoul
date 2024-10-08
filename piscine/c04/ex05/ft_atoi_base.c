/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:23:53 by phan              #+#    #+#             */
/*   Updated: 2023/01/28 10:32:53 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(char *str, char *base);
int		is_valid_base(char *base, int size);
char	*pass_str(char *str, int *sign);
int		get_base_idx(char c, char *base);
int		is_in_base(char c, char *base);

char	*pass_str(char *str, int *sign)
{
	*sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
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
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
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

int	is_in_base(char c, char *base)
{
	while (*base)
	{
		if (*base == c)
			return (1);
		base++;
	}
	return (0);
}

int	get_base_idx(char c, char *base)
{
	int	idx;

	idx = 0;
	while (*(base + idx))
	{
		if (*(base + idx) == c)
		{	
			return (idx);
		}
		idx++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	size;
	int	result;

	size = 0;
	result = 0;
	while (*(base + size))
		size++;
	if (!is_valid_base(base, size))
		return (0);
	str = pass_str(str, &sign);
	while (is_in_base(*str, base) && *str)
	{	
		result = result * size + get_base_idx(*str, base);
		str++;
	}
	return (sign * result);
}
