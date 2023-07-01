/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_metrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:23:11 by hanpilho          #+#    #+#             */
/*   Updated: 2023/07/01 20:13:12 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	rotate_x(double *x, double *y, double *z, double r)
{
	double	theta;
	double	prev_y;
	double	prev_z;

	(void)x;
	prev_y = *y;
	prev_z = *z;
	theta = M_PI / 6 + r;
	*y = prev_y * cos(theta) - prev_z * sin(theta);
	*z = prev_y * sin(theta) + prev_z * cos(theta);
}

void	rotate_y(double *x, double *y, double *z, double r)
{
	double	theta;
	double	prev_x;
	double	prev_z;

	(void)y;
	prev_x = *x;
	prev_z = *z;
	theta = M_PI / 6 + r;
	*x = prev_x * cos(theta) + prev_z * sin(theta);
	*z = -1 * prev_x * sin(theta) + prev_z * cos(theta);
}

void	rotate_z(double *x, double *y, double *z, double r)
{
	double	theta;
	double	prev_x;
	double	prev_y;

	(void)z;
	prev_x = *x;
	prev_y = *y;
	theta = M_PI / 4 * -1 + r;
	*x = prev_x * cos(theta) - prev_y * sin(theta);
	*y = prev_x * sin(theta) + prev_y * cos(theta);
}

void	rotate_all(double *x, double *y, double *z, double r)
{
	rotate_z(x, y, z, 0);
	rotate_y(x, y, z, r);
	rotate_x(x, y, z, 0);
}