/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:21:01 by phan              #+#    #+#             */
/*   Updated: 2023/06/29 20:56:56 by phan             ###   ########.fr       */
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
	wc -= 1;
	if (wc > 2 || wc == 0) // invalid data error
	{
		free_split(data_split);
		return (0);
	}
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
	if (*color == 'x' || *color == 'X')
		color++;
	if (ft_strlen(color) > 8 || ft_strlen(color) % 2 == 1)
		return (1);
	while (*color && *color != '\n')
	{
		// printf("idx : %d %s\n", ft_find(hex, ft_tolower(*color)), color);
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
			if (!ft_isnum(data_split[0])) // check valid map info
				exit(0);
			// printf("data_wc : %d %s\n", data_wc, data_split[1]);
			if (data_wc == 2 && check_color(data_split[1]) == -1)
				exit(0);
			// printf("color set ok\n");
			if (data_wc == 2)
				point.color = check_color(data_split[1]);
			else
				point.color = 0x00FFFFFF;
			point.x = x;
			point.z = ft_atoi(data_split[0]);
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
			if (!is_valid_data(line_split[c_width++])) // Error;
				exit(0);
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
