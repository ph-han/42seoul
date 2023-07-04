/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:13:02 by phan              #+#    #+#             */
/*   Updated: 2023/07/04 13:33:55 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
