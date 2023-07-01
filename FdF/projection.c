/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:13:02 by phan              #+#    #+#             */
/*   Updated: 2023/07/01 19:45:57 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	to_isometric(t_map *map)
{
	int	i;

	i = 0;
	while (i < (map->height) * (map->width))
	{
		rotate_z(&(map->r_map[i].x), &(map->r_map[i].y), &(map->r_map[i].z), 0);
		rotate_x(&(map->r_map[i].x), &(map->r_map[i].y), &(map->r_map[i].z), 0);
		i++;
	}
}
