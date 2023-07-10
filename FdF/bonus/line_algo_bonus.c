/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:12 by phan              #+#    #+#             */
/*   Updated: 2023/07/08 13:15:20 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	get_width_center(t_map *map)
{
	int	mid_i;
	int	mid_j;

	mid_i = map->width / 2;
	mid_j = map->width * (map->height / 2);
	return ((WIDTH / 2) - (map->r_map[mid_i + mid_j].x));
}

static int	get_height_center(t_map *map)
{
	int		mid_i;
	int		mid_j;

	mid_i = map->width / 2;
	mid_j = map->width * (map->height / 2);
	return ((HEIGHT / 2) - (map->r_map[mid_i + mid_j].y));
}

static int	is_over_window(t_map *map, double x, double y)
{
	return (x + get_width_center(map) + map->move_x > WIDTH \
		|| x + get_width_center(map) + map->move_x < 0 \
		|| y + get_height_center(map) + map->move_y > HEIGHT \
		|| y + get_height_center(map) + map->move_y < 0);
}

void	dda(t_img *data, t_map *map, t_point point1, t_point point2)
{
	t_line	line_info;
	int		i;

	line_info.dx = point2.x - point1.x;
	line_info.dy = point2.y - point1.y;
	if (fabs(line_info.dx) > fabs(line_info.dy))
		line_info.step = fabs(line_info.dx);
	else
		line_info.step = fabs(line_info.dy);
	line_info.xinc = line_info.dx / line_info.step;
	line_info.yinc = line_info.dy / line_info.step;
	i = -1;
	while (++i <= line_info.step)
	{
		if (fabs(line_info.dx) > fabs(line_info.dy))
			line_info.cinc = fabs(point2.x - point1.x) / line_info.step;
		else
			line_info.cinc = fabs(point2.y - point1.y) / line_info.step;
		if (!is_over_window(map, point1.x, point1.y))
			put_pixel(data, point1.x + get_width_center(map) + map->move_x, \
				point1.y + get_height_center(map) + map->move_y, \
				gradation(point1.color, point2.color, line_info.cinc));
		point1.x += line_info.xinc;
		point1.y += line_info.yinc;
	}
}
