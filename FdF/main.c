/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:54 by phan              #+#    #+#             */
/*   Updated: 2023/06/29 20:35:21 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"


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
	// for (int i = 0; i < map.height * map.width; i++)
	// {
	// 	// printf("(%d, %d, %d) ", map.r_map[i].x, map.r_map[i].y, map.r_map[i].z);
	// 	if ((i + 1) % map.width == 0)
	// 		// printf("\n");
	// }
	to_isometric(&map);
	mlx = mlx_init();
	if (!mlx)
		write(1, "mlx error\n", 11);
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "TEST");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("height / map.height %d\n", HEIGHT / map.height);
	for (int j = 0; j < map.height; j++)
	{
		for (int i = 0; i < map.width; i++)
		{
			map.r_map[i + map.width * j].x *= HEIGHT / (double)map.height * 4 / 10;
			map.r_map[i + map.width * j].y *= HEIGHT / (double)map.height * 4 / 10;
			map.r_map[i + map.width * j].z *= HEIGHT / (double)map.height * 4 / 10;
		}
	}
	for (int j = 0; j < map.width; j++)
		for (int i = 0; i < map.height - 1; i++)
			dda(&img, &map, map.r_map[j + map.width * i], map.r_map[j + map.width * (i + 1)]);
	for (int j = 0; j < map.height; j++)
		for (int i = 0; i < map.width - 1; i++)
			dda(&img, &map, map.r_map[i + map.width * j], map.r_map[i + 1 + map.width * j]);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
