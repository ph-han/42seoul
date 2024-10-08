/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:30:39 by phan              #+#    #+#             */
/*   Updated: 2023/10/12 13:56:53 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rotate_y(t_vec3 *x, t_vec3 *z, double theta)
{
	t_vec3	prev_x;
	t_vec3	prev_z;

	prev_x = *x;
	prev_z = *z;
	*z = sub_vec3(\
		scale_vec3(prev_z, cos(theta)), \
		scale_vec3(prev_x, sin(theta)) \
	);
	*x = add_vec3(\
		scale_vec3(prev_x, cos(theta)), \
		scale_vec3(prev_z, sin(theta)) \
	);
}

void	rotate_x(t_vec3 *y, t_vec3 *z, double theta)
{
	t_vec3	prev_y;
	t_vec3	prev_z;

	prev_y = *y;
	prev_z = *z;
	*z = sub_vec3(\
		scale_vec3(prev_z, cos(theta)), \
		scale_vec3(prev_y, sin(theta)) \
	);
	*y = add_vec3(\
		scale_vec3(prev_y, cos(theta)), \
		scale_vec3(prev_z, sin(theta)) \
	);
}

int rotate_cam(int keycode, t_env *env)
{
	double	theta;

	theta = 0.05;
	if (keycode == LEFT)
	{
		rotate_y(&env->rt.cam.axis[0], &env->rt.cam.axis[2], \
			-theta);
		render_world(*env);
	}
	else if (keycode == RIGHT)
	{
		rotate_y(&env->rt.cam.axis[0], &env->rt.cam.axis[2], \
			theta);
		render_world(*env);
	}
	else if (keycode == UP)
	{
		rotate_x(&env->rt.cam.axis[1], &env->rt.cam.axis[2], \
			theta);
		render_world(*env);
	}
	else if (keycode == DOWN)
	{
		rotate_x(&env->rt.cam.axis[1], &env->rt.cam.axis[2], \
			-theta);
		render_world(*env);
	}
	return (0);
}
