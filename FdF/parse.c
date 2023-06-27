/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:21:01 by phan              #+#    #+#             */
/*   Updated: 2023/06/27 14:16:32 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_map_coordinate_info(int fd, t_map *map, int x, int y)
{
	t_point	point;
	char	*line;
	char	**line_split;

	line = get_next_line(fd);
	while (line)
	{
		point.y = y;
		line_split = ft_split(line, ' ');
		free(line);
		x = 0;
		while(line_split[x])
		{
			if (!ft_isnum(line_split[x])) // check valid map info
				exit(0);
			point.x = x;
			point.z = ft_atoi(line_split[x]);
			map->r_map[x++ + map->width * y] = point;
		}
		free_split(line_split);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
}

static void	get_map_info(int fd, t_map *map, int c_width)
{
	char	*line;
	char	**line_split;

	line = get_next_line(fd);
	map->width = get_map_width(line);
	map->height = 0;
	c_width = 0;
	while (line)
	{
		line_split = ft_split(line, ' ');
		free(line);
		if (!line_split || !*line_split) // Error
			exit(0);
		while (line_split[c_width])
			c_width++;
		free_split(line_split);
		if (c_width != map->width) // Error
			exit(0);
		map->height++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	parse_map(t_map *map, char *filename)
{
	int	fd;
	
	fd = open(filename, O_RDONLY);
	get_map_info(fd, map, 0);
	map->r_map = (t_point *)malloc(sizeof(t_point) * map->width * map->height);
	if (!(map->r_map)) // malloc error
		exit(0);
	fd = open(filename, O_RDONLY);
	get_map_coordinate_info(fd, map, 0, 0);
}
