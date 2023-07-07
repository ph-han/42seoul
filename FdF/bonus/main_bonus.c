/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:54 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:35 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	restore(t_fdf *fdf)
{
	ft_mapcpy(fdf->map->o_map, fdf->map->r_map, \
		fdf->map->width * fdf->map->height);
	to_isometric(fdf->map, fdf->angle);
	scaling(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
	return (0);
}

void	move(int key_code, t_fdf *fdf)
{
	if (key_code == 123)
		move_left(fdf);
	else if (key_code == 124)
		move_right(fdf);
	else if (key_code == 125)
		move_down(fdf);
	else if (key_code == 126)
		move_up(fdf);
}

static int	k_hooks(int key_code, t_fdf *fdf)
{
	if (key_code == 53)
		close_win(fdf);
	if (key_code == 18)
		rotate_map_x(fdf, 0.05);
	else if (key_code == 19)
		rotate_map_x(fdf, -0.05);
	else if (key_code == 20)
		rotate_map_y(fdf, 0.05);
	else if (key_code == 21)
		rotate_map_y(fdf, -0.05);
	else if (key_code == 22)
		rotate_map_z(fdf, 0.05);
	else if (key_code == 23)
		rotate_map_z(fdf, -0.05);
	else if (key_code == 1)
		mlx_loop_hook(fdf->mlx, auto_rotate, fdf);
	else if (key_code == 123 || key_code == 124 || \
		key_code == 125 || key_code == 126)
		move(key_code, fdf);
	else if (key_code == 15 || key_code == 34)
		restore(fdf);
	else if (key_code == 35)
		to_plan(fdf);
	return (0);
}

static int	m_hooks(int key_code, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (key_code == 5)
		zoom_in(fdf);
	else if (key_code == 4)
		zoom_out(fdf);
	return (0);
}

int	main(int ac, char *av[])
{
	t_fdf	fdf;

	if (ac != 2)
		return (0);
	if (!is_valid_filename(av[1]))
		ft_perror("Invalid filename!");
	init_fdf(&fdf);
	parse_map(fdf.map, av[1]);
	to_isometric(fdf.map, fdf.angle);
	scaling(fdf.map);
	fdf.mlx = mlx_init();
	if (!fdf.mlx)
		ft_perror("MLX ERROR!");
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FdF");
	draw_map(&fdf);
	mlx_mouse_hook(fdf.win, m_hooks, &fdf);
	mlx_hook(fdf.win, 2, 1L << 0, k_hooks, &fdf);
	mlx_hook(fdf.win, 17, 1L << 5, close_win, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
