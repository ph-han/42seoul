/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:13:02 by phan              #+#    #+#             */
/*   Updated: 2023/06/30 12:16:21 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	rotate_x(double *x, double *y, double *z)
{
	double	theta;
	double	prev_y;
	double	prev_z;
	
	(void)x;
	prev_y = *y;
	prev_z = *z;
	theta = M_PI / 3;
	*y = prev_y * cos(theta) - prev_z * sin(theta);
	*z = prev_y * sin(theta) + prev_z * cos(theta);
}

void	rotate_y(double *x, double *y, double *z)
{
	double	theta;
	double	prev_x;
	double	prev_z;

	(void)y;
	prev_x = *x;
	prev_z = *z;
	theta = M_PI / 4;
	*x = prev_x * cos(theta) + prev_z * sin(theta);
	*z = -1 * prev_x * sin(theta) + prev_z * cos(theta);
}

void	rotate_z(double *x, double *y, double *z)
{
	double	theta;
	double	prev_x;
	double	prev_y;

	(void)z;
	prev_x = *x;
	prev_y = *y;
	theta = M_PI / 4 * -1;
	*x = prev_x * cos(theta) - prev_y * sin(theta);
	*y = prev_x * sin(theta) + prev_y * cos(theta);
}

void	to_isometric(t_map *map)
{
	int	i;

	i = 0;
	while (i < (map->height) * (map->width))
	{
		rotate_z(&(map->r_map[i].x), &(map->r_map[i].y), &(map->r_map[i].z));
		rotate_x(&(map->r_map[i].x), &(map->r_map[i].y), &(map->r_map[i].z));
		i++;
	}
}
