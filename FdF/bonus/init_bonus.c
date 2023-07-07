/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:10:04 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:23 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_fdf(t_fdf *fdf)
{
	fdf->map = (t_map *)malloc(sizeof(t_map));
	fdf->img = (t_img *)malloc(sizeof(t_img));
	fdf->angle = (t_angle *)malloc(sizeof(t_angle));
}

void	init_img(t_fdf *fdf)
{
	fdf->img->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, \
		&fdf->img->bits_per_pixel, &fdf->img->line_length, &fdf->img->endian);
}

void	init_angle(t_angle *angle)
{
	angle->alpha = M_PI / 3;
	angle->beta = M_PI / 6;
	angle->gamma = M_PI / 4 * -1;
}

void	init_map(t_map *map)
{
	map->ratio = HEIGHT / (double)map->height * 0.4;
	map->move_x = 0;
	map->move_y = 0;
}
