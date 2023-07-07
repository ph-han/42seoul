/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:40:11 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:07 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	is_valid_filename(char *filename)
{
	char	**filename_split;
	int		wc;

	filename_split = ft_split(filename, '.');
	wc = 0;
	while (filename_split[wc++])
		;
	if (wc <= 2)
		return (0);
	if (ft_strncmp(filename_split[wc - 2], "fdf", 4) != 0)
	{
		free_split(filename_split);
		return (0);
	}
	free_split(filename_split);
	return (1);
}

int	is_vaild_num(char *data)
{
	if (*data == '-' || *data == '+')
		data++;
	if (!*data)
		return (0);
	while (*data && *data != '\n')
	{
		if (!ft_isdigit(*data))
			return (0);
		data++;
	}
	return (1);
}

int	is_valid_data(char *data)
{
	char	**data_split;
	int		wc;

	data_split = ft_split(data, ',');
	wc = 0;
	while (data_split[wc])
		wc++;
	if (wc > 2 || wc == 0)
	{
		free_split(data_split);
		return (0);
	}
	free_split(data_split);
	return (wc);
}

long	check_and_set_color(char *color)
{
	char			*hex;
	unsigned int	result;

	if (!color)
		return (-1);
	hex = "0123456789abcdef";
	result = 0;
	if (*color == '0')
		color++;
	else
		return (-1);
	if (*color == 'x' || *color == 'X')
		color++;
	else
		return (-1);
	if (fdf_strlen(color) > 8 || fdf_strlen(color) % 2 == 1)
		return (-1);
	while (*color && *color != '\n')
	{
		if (ft_find(hex, ft_tolower(*color)) == -1)
			return (-1);
		result = 16 * result + ft_find(hex, ft_tolower(*color));
		color++;
	}
	return (result);
}
