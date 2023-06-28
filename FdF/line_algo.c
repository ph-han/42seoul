/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:12 by phan              #+#    #+#             */
/*   Updated: 2023/06/28 21:14:52 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width_center(t_map *map)
{
	return ((WIDTH / 2) - (map->width * 10));
}

int	get_height_center(t_map *map)
{
	return ((HEIGHT / 2) - (map->height * 10));
}

void	dda(t_img *data, t_map *map, t_point point1, t_point point2)
{
	double	dx;
	double	dy;
	double	step;
	double	xinc;
	double	yinc;
	int	i;

(void)map;
	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	if (!step)
		return ;
	xinc = dx / step;
	yinc = dy / step;
	i = 0;
	point1.x = point1.x;
	point1.y = point1.y;
	while (i <= step)
	{
		my_mlx_pixel_put(data, point1.x + 500, point1.y + 500, 0x00FFFFFF);
		point1.x = point1.x + xinc;
		point1.y = point1.y + yinc;
		i++;
	}
}
