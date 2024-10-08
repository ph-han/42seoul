/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:27:23 by hcho2             #+#    #+#             */
/*   Updated: 2023/10/04 20:38:56 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_ambient(char **args, t_amb *amb)
{
	set_ratio(args[1], &amb->ratio);
	set_color(args[2], &amb->color);
}

void	set_light(char **args, t_light *light)
{
	set_point(args[1], &light->point);
	set_ratio(args[2], &light->ratio);
	set_color(args[3], &light->color);
}

void	init_cam_metrix(t_vec3 (*metrix)[3], double p, double t)
{
	(*metrix)[0] = set_vec3(
			cos(p),
			-1 * sin(p) * sin(t),
			-1 * sin(p) * cos(t));
	(*metrix)[1] = set_vec3(
			sin(p),
			cos(p) * sin(t),
			cos(p) * cos(t));
	(*metrix)[2] = set_vec3(
			0,
			-1 * cos(t),
			sin(t));
}

void	set_cam_axis(t_cam *cam)
{
	t_vec3	vup;

	vup = set_vec3(0, 1, 0);
	if ((cam->dir.y != 0.0) && (cam->dir.x == 0 && cam->dir.z == 0))
		vup = set_vec3(0, 0, 1);
	cam->axis[2] = unit_vec3(cam->dir);
	cam->axis[0] = unit_vec3(cross_vec3(vup, cam->axis[2]));
	cam->axis[1] = unit_vec3(cross_vec3(cam->axis[2], cam->axis[0]));
}

void	set_camera(char **args, t_cam *cam)
{
	set_point(args[1], &cam->point);
	set_dir(args[2], &cam->dir);
	cam->view_angle = ft_atoi(args[3]) / 2.0;
	cam->fov = tan(cam->view_angle * (M_PI / 180.0));
	set_cam_axis(cam);
	cam->ratio = (double)(WIDTH) / HEIGHT;
}
