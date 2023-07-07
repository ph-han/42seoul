/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:13:02 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:50 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	to_plan(t_fdf *fdf)
{
	ft_mapcpy(fdf->map->o_map, fdf->map->r_map,
		fdf->map->width * fdf->map->height);
	init_map(fdf->map);
	scaling(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
}

void	to_isometric(t_map *map, t_angle *angle)
{
	int	i;

	i = 0;
	init_angle(angle);
	while (i < (map->height) * (map->width))
	{
		rotate_z(map->r_map + i, angle);
		rotate_x(map->r_map + i, angle);
		i++;
	}
	init_map(map);
}
