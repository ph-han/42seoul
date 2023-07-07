/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:32:37 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:26:01 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	scaling(t_map *map)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			map->r_map[i + map->width * j].x *= map->ratio;
			map->r_map[i + map->width * j].y *= map->ratio;
			map->r_map[i + map->width * j].z *= map->ratio;
			i++;
		}
		j++;
	}
}
