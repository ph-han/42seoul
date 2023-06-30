/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:39:10 by phan              #+#    #+#             */
/*   Updated: 2023/06/30 21:21:28 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void put_pixel(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map_column(t_img *img, t_map *map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	printf("draw map colum\n");
	j = 0;
	while (j < map->width)
	{
		i = 0;
		while (i < map->height - 1)
		{
			printf("%f %f\n", p1.x, p1.y);
			p1 = map->r_map[j + map->width * i];
			p2 = map->r_map[j + map->width * (i + 1)];
			dda(img, map, p1, p2);
			i++;
		}
		j++;
	}
}

void	draw_map_row(t_img *img, t_map *map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width - 1)
		{
			p1 = map->r_map[i + map->width * j];
			p2 = map->r_map[i + 1 + map->width * j];
			dda(img, map, p1, p2);
			i++;
		}
		j++;
	}
}
