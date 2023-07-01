/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:12:45 by phan              #+#    #+#             */
/*   Updated: 2023/07/01 18:34:57 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

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
	printf("data : %d\n", *data);
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

int	is_valid_filename(char *filename)
{
	char	**filename_split;
	int		wc;

	filename_split = ft_split(filename, '.');
	wc = 0;
	while (filename_split[wc++]);
	if (wc <= 2)
		return (0);
	if (ft_strncmp(filename_split[wc - 2], "fdf\0", 4) != 0)
	{
		free_split(filename_split);
		return (0);
	}
	free_split(filename_split);
	return (1);
}
