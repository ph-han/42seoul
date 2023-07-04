/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:12:45 by phan              #+#    #+#             */
/*   Updated: 2023/07/04 13:10:40 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **split_line)
{
	int	idx;

	idx = 0;
	while (split_line[idx])
		free(split_line[idx++]);
	free(split_line);
}

int	get_map_width(char *line)
{
	char	**line_split;
	int		width;

	width = 0;
	line_split = ft_split(line, ' ');
	while (line_split[width])
		width++;
	free_split(line_split);
	return (width);
}

int	ft_isnum(char *data)
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

int	ft_find(char *hex, char c)
{
	int	idx;

	idx = 0;
	while (hex[idx])
	{
		if (hex[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int fdf_strlen(char *s)
{
	int len;

	len = 0;
	while (*(s + len) && *(s + len) != '\n')
		len++;
	return (len);
}
