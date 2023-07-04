/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:12 by phan              #+#    #+#             */
/*   Updated: 2023/07/04 12:17:07 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width_center(t_map *map)
{
	int	mid_i;
	int	mid_j;

	mid_i = map->width / 2;
	mid_j = map->width * (map->height / 2);
	return ((WIDTH / 2) - (map->r_map[mid_i + mid_j].x) + 100);
}

int	get_height_center(t_map *map)
{
	int		mid_i;
	int		mid_j;
	double	min_y;
	int		i;

	mid_i = map->width / 2;
	mid_j = map->width * (map->height / 2);
	i = -1;
	min_y = map->r_map[0].y;
	return ((HEIGHT / 2) - (map->r_map[mid_i + mid_j].y) + 100);
}

int	is_over_window(t_map *map, t_point point1)
{
	return (point1.x + get_width_center(map) + map->move_x > WIDTH \
		|| point1.x + get_width_center(map) + map->move_x < 0 \
		|| point1.y + get_height_center(map) + map->move_y > HEIGHT \
		|| point1.y + get_height_center(map) + map->move_y < 0);
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
	if (!line_info.step)
		return ;
	line_info.xinc = line_info.dx / line_info.step;
	line_info.yinc = line_info.dy / line_info.step;
	i = -1;
	while (++i <= line_info.step)
	{
		if (is_over_window(map, point1))
			continue ;
		put_pixel(data, point1.x + get_width_center(map) + map->move_x,
				  point1.y + get_height_center(map) + map->move_y, point1.color);
		point1.x = point1.x + line_info.xinc;
		point1.y = point1.y + line_info.yinc;
	}
}
