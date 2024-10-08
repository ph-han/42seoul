/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:31:16 by phan              #+#    #+#             */
/*   Updated: 2023/10/02 14:34:24 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	move_cam(t_rt *rt, t_vec3 delta)
{
	rt->cam.point = add_vec3(rt->cam.point, delta);
}

int	translate_cam(int keycode, t_env *env)
{
	double	delta;

	delta = 0.9;
	if (keycode == W)
		move_cam(&(env->rt), scale_vec3(env->rt.cam.axis[2], delta));
	else if (keycode == S)
		move_cam(&(env->rt), scale_vec3(env->rt.cam.axis[2], -delta));
	else if (keycode == A)
		move_cam(&(env->rt), scale_vec3(env->rt.cam.axis[0], delta));
	else if (keycode == D)
		move_cam(&(env->rt), scale_vec3(env->rt.cam.axis[0], -delta));
	else if (keycode == SP)
		move_cam(&(env->rt), scale_vec3(env->rt.cam.axis[1], delta));
	else if (keycode == CTRL)
		move_cam(&(env->rt), scale_vec3(env->rt.cam.axis[1], -delta));
	render_world(*env);
	return (0);
}
