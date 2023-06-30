/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:54 by phan              #+#    #+#             */
/*   Updated: 2023/06/30 19:55:15 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void put_pixel(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(int ac, char *av[])
{
	t_map map;
	void *mlx;
	void *win;
	t_img img;

	if (ac != 2)
		return (0);
	parse_map(&map, av[1]);
	to_isometric(&map);
	scaling(&map, 5 / 10.0);
	mlx = mlx_init();
	if (!mlx)
		write(1, "mlx error\n", 11);
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "TEST");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_map_column(&img, &map);
	draw_map_row(&img, &map);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
