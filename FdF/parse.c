/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:21:01 by phan              #+#    #+#             */
/*   Updated: 2023/07/01 18:24:46 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	is_valid_data(char *data)
{
	char	**data_split;
	int		wc;

	data_split = ft_split(data, ',');
	wc = 0;
	while (data_split[wc++]);
	wc--;
	if (wc > 2 || wc == 0) // invalid data error
	{
		free_split(data_split);
		return (0);
	}
	free_split(data_split);
	return (wc);
}

int ft_find(char *hex, char c)
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

int	fdf_strlen(char *s)
{
	int	len;

	len = 0;
	while (*(s + len) && *(s + len) != '\n')
		len++;
	return (len);
}

int	check_color(char *color)
{
	char	*hex;
	int		result;

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

static void	get_map_coordinate_info(int fd, t_map *map, int x, int y)
{
	t_point	point;
	char	*line;
	char	**line_split;
	char	**data_split;
	int		data_wc;

	line = get_next_line(fd);
	while (line)
	{
		point.y = y;
		line_split = ft_split(line, ' ');
		free(line);
		x = 0;
		while(line_split[x])
		{
			data_split = ft_split(line_split[x], ',');
			data_wc = is_valid_data(line_split[x]);
			if (!ft_isnum(data_split[0]))
				ft_perror("Invalid map data ft_isnum!");
			if (data_wc == 2)
			{
				point.color = check_color(data_split[1]);
				if (point.color == -1)
					ft_perror("Invalid color!");
			}
			else
				point.color = 0x00FFFFFF;
			point.x = x;
			point.z = ft_atoi(data_split[0]);
			map->r_map[x++ + map->width * y] = point;
			free_split(data_split);
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
	while (line)
	{
		line_split = ft_split(line, ' ');
		free(line);
		if (!line_split || !*line_split) // Error
			ft_perror("Invalid map info!");
		c_width = 0;
		while (line_split[c_width])
			if (!is_valid_data(line_split[c_width++])) // Error;
				ft_perror("Invalid map data!");
		free_split(line_split);
		printf("c_width: %d map width : %d\n", c_width, (int)map->width);
		if (c_width != (int)(map->width)) // Error
			ft_perror("Map size error!");
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
	if (fd < 0)
		ft_perror("file is not exist!");
	get_map_info(fd, map, 0);
	map->r_map = (t_point *)malloc(sizeof(t_point) * map->width * map->height);
	if (!(map->r_map)) // malloc error
		ft_perror("map malloc error!");
	fd = open(filename, O_RDONLY);
	get_map_coordinate_info(fd, map, 0, 0);
}
