/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:48:30 by hcho2             #+#    #+#             */
/*   Updated: 2023/10/08 13:57:50 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_sphere(char **args, t_object *obj, t_rt *rt)
{
	obj->type = SPHERE;
	set_point(args[1], &obj->sphere.center);
	set_point(args[1], &obj->orig);
	obj->sphere.radius = ft_atof(args[2]) / 2.0;
	set_color(args[3], &obj->diffuse);
	obj->amb = scale_vec3(obj->diffuse, 0.2);
	obj->specular = set_vec3(rt->light.color.r, \
		rt->light.color.g, rt->light.color.b);
	obj->check_ray_collison = check_ray_collison_sphere;
}

void	set_plane(char **args, t_object *obj, t_rt *rt)
{
	obj->type = PLANE;
	set_point(args[1], &obj->plane.point);
	set_point(args[1], &obj->orig);
	set_dir(args[2], &obj->plane.normal);
	set_color(args[3], &obj->diffuse);
	obj->amb = scale_vec3(obj->diffuse, 0.2);
	obj->specular = set_vec3(rt->light.color.r, \
		rt->light.color.g, rt->light.color.b);
	obj->check_ray_collison = check_ray_collison_plane;
}

void	set_cylinder(char **args, t_object *obj, t_rt *rt)
{
	obj->type = CYLINDER;
	set_point(args[1], &obj->cylinder.center);
	set_point(args[1], &obj->orig);
	set_dir(args[2], &obj->cylinder.normal);
	obj->cylinder.diameter = ft_atof(args[3]);
	obj->cylinder.height = ft_atof(args[4]);
	set_color(args[5], &obj->diffuse);
	obj->amb = scale_vec3(obj->diffuse, 0.2);
	obj->specular = set_vec3(rt->light.color.r, \
		rt->light.color.g, rt->light.color.b);
	obj->check_ray_collison = check_ray_collison_cylinder;
}

void	set_object(int type, char **args, t_rt *rt)
{
	t_object	*new;

	if (type == SPHERE)
	{
		new = new_obj();
		set_sphere(args, new, rt);
		obj_lstadd_back(&(rt->objs), new);
	}
	else if (type == PLANE)
	{
		new = new_obj();
		set_plane(args, new, rt);
		obj_lstadd_back(&(rt->objs), new);
	}
	else if (type == CYLINDER)
	{
		new = new_obj();
		set_cylinder(args, new, rt);
		obj_lstadd_back(&(rt->objs), new);
	}
}
