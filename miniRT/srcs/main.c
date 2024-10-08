/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:18:45 by hcho2             #+#    #+#             */
/*   Updated: 2023/10/12 13:52:59 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
	{
		write(1, "Error: Check your number of argument\n", 38);
		return (1);
	}
	env.rt.objs = NULL;
	parse_input(av[1], &env.rt);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "miniRT");
	env.img.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, \
		&env.img.line_length, &env.img.endian);
	render_world(env);
	// env.is_left_down = 0;
	// env.is_right_down = 0;
	mlx_hook(env.win, ON_KEYDOWN, 1L << 0, key_hook, &env);
	// mlx_hook(env.win, ON_MOUSEDOWN, 1L << 0, mouse_down_hook, &env);
	// mlx_hook(env.win, ON_MOUSEUP, 1L << 0, mouse_up_hook, &env);
	// mlx_hook(env.win, ON_MOUSEMOVE, 1L << 0, mouse_move_hook, &env);
	mlx_hook(env.win, 17, 1L << 5, close_win, &env);
	mlx_loop(env.mlx);
}
