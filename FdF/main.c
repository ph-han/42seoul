/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:54 by phan              #+#    #+#             */
/*   Updated: 2023/06/30 23:05:59 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	ft_perror(char *e_msg)
{
	ft_putendl_fd(e_msg, 2);
	exit(1);
}

int	win_close(int key_code, t_vars *vars)
{
	printf("code : %d\n", key_code);
	(void)vars;
	if (key_code == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	check_leaks(void)
{
	system("leaks --list -- fdf");
}

int main(int ac, char *av[])
{
	t_map	map;
	t_vars	vars;
	t_img	img;

	atexit(check_leaks);
	if (ac != 2)
		return (0);
	if (!is_valid_filename(av[1]))
		ft_perror("Invalid filename!");
	parse_map(&map, av[1]);
	to_isometric(&map);
	scaling(&map, 5 / 10.0);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		write(1, "mlx error\n", 11);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "TEST");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_map_column(&img, &map);
	draw_map_row(&img, &map);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, win_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
