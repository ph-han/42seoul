/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:54:07 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:26:15 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	zoom_in(t_fdf *fdf)
{
	fdf->map->ratio = 1.05;
	scaling(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
}

void	zoom_out(t_fdf *fdf)
{
	fdf->map->ratio = 0.95;
	scaling(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
}
