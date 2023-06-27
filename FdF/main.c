/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:54 by phan              #+#    #+#             */
/*   Updated: 2023/06/27 21:23:00 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;
 
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char *av[])
{
	t_map	map;
	void	*mlx;
	void	*win;
	t_img	img;

	if (ac != 2)
		return (0);
	parse_map(&map, av[1]);
	for (int i = 0; i < map.height * map.width; i++)
	{
		printf("(%d, %d, %d) ", map.r_map[i].x, map.r_map[i].y, map.r_map[i].z);
		if ((i + 1) % map.width == 0)
			printf("\n");
	}
	to_isometric(&map);
	mlx = mlx_init();
	if (!mlx)
		write(1, "mlx error\n", 11);
	win = mlx_new_window(mlx, 1920, 1080, "TEST");
	img.img = mlx_new_image(mlx, map.width * 100, map.height * 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 0; i < map.height * map.width; i++)
	{
		printf("(%d, %d, %d) ", map.r_map[i].x, map.r_map[i].y, map.r_map[i].z);
		if ((i + 1) % map.width == 0)
			printf("\n");
		my_mlx_pixel_put(&img, map.r_map[i].x * 10, map.r_map[i].y * 10, 0x00FFFFFF);
	}
	mlx_put_image_to_window(mlx, win, img.img, 1920 / 2 - 100, 1080 / 2 - 100);
	mlx_loop(mlx);
	return (0);
}
