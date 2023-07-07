/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:51:29 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:40 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_left(t_fdf *fdf)
{
	fdf->map->move_x += -10;
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
}

void	move_right(t_fdf *fdf)
{
	fdf->map->move_x += 10;
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
}

void	move_up(t_fdf *fdf)
{
	fdf->map->move_y += -10;
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
}

void	move_down(t_fdf *fdf)
{
	fdf->map->move_y += 10;
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
}
