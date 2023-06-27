/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:13:02 by phan              #+#    #+#             */
/*   Updated: 2023/06/27 21:24:47 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *point)
{
	int	i;
	int theta;

	i = 0;
	theta = asin(tan(M_PI / 6));

	point->y = point->y * cos(theta) \
		+ point->z * sin(theta);
	point->z = point->y * -1 * sin(theta) \
		+ point->z * cos(theta);

}

void	rotate_y(t_point *point)
{
	int i;
	int theta;

	i = 0;
	theta = M_PI / 4;
	point->y = point->y * cos(theta) + point->z * sin(theta);
	point->z = point->y * -1 * sin(theta) + point->z * cos(theta);
}

void	to_isometric(t_map *map)
{
	int	i;

	i = 0;
	while (i < (map->height) * (map->width))
	{
		rotate_x((map->r_map) + i);
		rotate_y((map->r_map) + i);
		i++;
	}
}