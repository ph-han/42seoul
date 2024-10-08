/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:40:45 by phan              #+#    #+#             */
/*   Updated: 2023/01/31 19:00:22 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base(char *str, char *base);
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
	str = pass_str(str, &sign);
	while (is_in_base(*str, base) && *str)
	{	
		result = result * size + get_base_idx(*str, base);
		str++;
	}
	return (sign * result);
}
