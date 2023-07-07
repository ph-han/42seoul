/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_metrix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:23:11 by hanpilho          #+#    #+#             */
/*   Updated: 2023/07/07 12:25:56 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x(t_point *point, t_angle *angle)
{
	double	prev_y;
	double	prev_z;

	prev_y = point->y;
	prev_z = point->z;
	(point->y) = prev_y * cos(angle->alpha) - prev_z * sin(angle->alpha);
	(point->z) = prev_y * sin(angle->alpha) + prev_z * cos(angle->alpha);
}

void	rotate_y(t_point *point, t_angle *angle)
{
	double	prev_x;
	double	prev_z;

	prev_x = point->x;
	prev_z = point->z;
	point->x = prev_x * cos(angle->beta) + prev_z * sin(angle->beta);
	point->z = -1 * prev_x * sin(angle->beta) + prev_z * cos(angle->beta);
}

void	rotate_z(t_point *point, t_angle *angle)
{
	double	prev_x;
	double	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(angle->gamma) - prev_y * sin(angle->gamma);
	point->y = prev_x * sin(angle->gamma) + prev_y * cos(angle->gamma);
}
