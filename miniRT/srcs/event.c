/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:59:40 by phan              #+#    #+#             */
/*   Updated: 2023/10/12 13:56:47 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	close_win(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == ESC)
		close_win(env);
	else if (keycode == W || keycode == A || keycode == S \
	|| keycode == D || keycode == SP || keycode == CTRL)
		translate_cam(keycode, env);
	else if (keycode == LEFT || keycode == RIGHT || keycode == DOWN || keycode == UP)
		rotate_cam(keycode, env);
	return (0);
}

// int	mouse_down_hook(int button, int x, int y, t_env *env)
// {
// 	if (button == 1)
// 	{
// 		env->x = x;
// 		env->is_left_down = 1;
// 	}
// 	if (button == 2)
// 	{
// 		env->y = y;
// 		env->is_right_down = 1;
// 	}
// 	return (0);
// }

// int	mouse_up_hook(int button, int x, int y, t_env *env)
// {
// 	(void)x;
// 	(void)y;
// 	if (button == 1)
// 		env->is_left_down = 0;
// 	if (button == 2)
// 		env->is_right_down = 0;
// 	return (0);
// }

// int	mouse_move_hook(int x, int y, t_env *env)
// {
// 	double	theta;

// 	theta = 0.0001;
// 	if (env->is_left_down)
// 	{
// 		rotate_y(&env->rt.cam.axis[0], &env->rt.cam.axis[2], \
// 			(x - env->x) * theta);
// 		render_world(*env);
// 	}
// 	if (env->is_right_down)
// 	{
// 		rotate_x(&env->rt.cam.axis[1], &env->rt.cam.axis[2], \
// 			(y - env->y) * theta);
// 		render_world(*env);
// 	}
// 	return (0);
// }
