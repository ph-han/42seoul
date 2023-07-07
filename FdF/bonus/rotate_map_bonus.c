/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:05:18 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:54 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_map_x(t_fdf *fdf, double r)
{
	int	i;

	i = -1;
	fdf->angle->alpha = -1 * r;
	fdf->angle->beta = r;
	fdf->angle->gamma = r;
	while (++i < (fdf->map->height) * (fdf->map->width))
	{
		rotate_z(fdf->map->r_map + i, fdf->angle);
		rotate_y(fdf->map->r_map + i, fdf->angle);
		rotate_x(fdf->map->r_map + i, fdf->angle);
	}
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
}

void	rotate_map_y(t_fdf *fdf, double r)
{
	int	i;

	i = -1;
	fdf->angle->alpha = r;
	fdf->angle->beta = r;
	fdf->angle->gamma = r;
	while (++i < (fdf->map->height) * (fdf->map->width))
	{
		rotate_z(fdf->map->r_map + i, fdf->angle);
		rotate_y(fdf->map->r_map + i, fdf->angle);
		rotate_x(fdf->map->r_map + i, fdf->angle);
	}
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
}

void	rotate_map_z(t_fdf *fdf, double r)
{
	int	i;

	i = -1;
	fdf->angle->beta = r;
	while (++i < (fdf->map->height) * (fdf->map->width))
		rotate_y(fdf->map->r_map + i, fdf->angle);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
}

int	auto_rotate(t_fdf *fdf)
{
	rotate_map_z(fdf, -0.2);
	rotate_map_y(fdf, 0.05);
	rotate_map_x(fdf, -0.05);
	return (0);
}
