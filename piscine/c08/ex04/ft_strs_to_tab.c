/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:37:42 by phan              #+#    #+#             */
/*   Updated: 2023/02/02 20:01:55 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

char	*ft_strdup(char *src)
{
	char	*dup;
	int		size;
	int		i;

	size = 0;
	while (*(src + size))
		size++;
	dup = (char *)malloc(size + 1);
	dup[0] = '\0';
	i = 0;
	while (*src)
	{
		*(dup + i) = *src;
		src++;
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*temp;
	int			i;

	temp = (t_stock_str *)malloc(sizeof(t_stock_str *) * ac + 1);
	if (temp == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		temp[i].size = ft_strlen(av[i]);
		temp[i].str = av[i];
		temp[i].copy = ft_strdup(av[i]);
	}
	temp[i].str = 0;
	return (temp);
}
