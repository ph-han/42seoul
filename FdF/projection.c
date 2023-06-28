/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:13:02 by phan              #+#    #+#             */
/*   Updated: 2023/06/28 19:33:05 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	rotate_x(int *x, int *y, int *z)
void	rotate_x(double *x, double *y, double *z)
{
	double	theta;
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_x = (double)*x;
	prev_y = (double)*y;
	prev_z = (double)*z;
	// theta = asin(tan(M_PI / 6));
	theta = M_PI / 3;
	*x = prev_x;
	*y = prev_y * cos(theta) - prev_z * sin(theta);
	*z = prev_y * sin(theta) + prev_z * cos(theta);
}

// void	rotate_y(int *x, int *y, int *z)
void	rotate_y(double *x, double *y, double *z)
{
	double	theta;
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_x = (double)*x;
	prev_y = (double)*y;
	prev_z = (double)*z;
	theta = M_PI / 4;
	*x = prev_x * cos(theta) + prev_z * sin(theta);
	*y = prev_y;
	*z = -1 * prev_x * sin(theta) + prev_z * cos(theta);
}

// void	rotate_z(int *x, int *y, int *z)
void	rotate_z(double *x, double *y, double *z)
{
	double	theta;
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_x = (double)*x;
	prev_y = (double)*y;
	prev_z = (double)*z;
	theta = M_PI / 4 * -1;
	// theta = M_PI / 6;
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