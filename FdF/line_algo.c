/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:12 by phan              #+#    #+#             */
/*   Updated: 2023/06/29 13:00:12 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width_center(t_map *map)
{
	int	mid_i;
	int	mid_j;

	mid_i = map->width / 2;
	mid_j = map->width * (map->height / 2);
	return ((WIDTH / 2) - (map->r_map[mid_i + mid_j].x));
}

int	get_height_center(t_map *map)
{
	int	mid_i;
	int	mid_j;

	mid_i = map->width / 2;
	mid_j = map->width * (map->height / 2);
	return ((HEIGHT / 2) - (map->r_map[mid_i + mid_j].y));
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
	i = 0;
	point1.x = point1.x;
	point1.y = point1.y;
	while (i <= line_info.step)
	{
		if (point1.x + get_width_center(map) > WIDTH || point1.x + get_width_center(map) < 0)
		{
			i++;
			continue ;
		}
		if (point1.y + get_height_center(map) > HEIGHT || point1.y + get_height_center(map) < 0)
		{
			i++;
			continue ;
		}
		my_mlx_pixel_put(data, point1.x + get_width_center(map),
						 point1.y + get_height_center(map), 0x00FFFFFF);
		point1.x = point1.x + line_info.xinc;
		point1.y = point1.y + line_info.yinc;
		i++;
	}
}
