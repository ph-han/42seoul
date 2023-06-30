/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:32:37 by phan              #+#    #+#             */
/*   Updated: 2023/06/30 19:55:03 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	scaling(t_map *map, double ratio)
{
	int		i;
	int		j;
	double	scale;

	j = 0;
	scale = HEIGHT / (double)map->height * ratio;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			map->r_map[i + map->width * j].x *= scale;
			map->r_map[i + map->width * j].y *= scale;
			map->r_map[i + map->width * j].z *= scale;
			i++;
		}
		j++;
	}
}

