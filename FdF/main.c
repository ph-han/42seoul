/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:54 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:24:00 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	k_hooks(int key_code, t_fdf *fdf)
{
	if (key_code == 53)
		close_win(fdf);
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
	mlx_hook(fdf.win, 2, 1L << 0, k_hooks, &fdf);
	mlx_hook(fdf.win, 17, 1L << 5, close_win, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
