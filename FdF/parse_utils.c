/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:12:45 by phan              #+#    #+#             */
/*   Updated: 2023/06/29 16:22:47 by phan             ###   ########.fr       */
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
	return (width);
}

int	ft_isnum(char *data)
{
	if (ft_strlen(data) > 1 && \
		(*data == '-' || *data == '+'))
		data++;
	while (*data && *data != '\n')
	{
		if (!ft_isdigit(*data))
			return (0);
		data++;
	}
	return (1);
}
