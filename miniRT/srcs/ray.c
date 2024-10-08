/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:03:37 by phan              #+#    #+#             */
/*   Updated: 2023/10/11 14:17:11 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_hit	find_closest_collison(t_ray ray, t_object *objects)
{
	double	closest_d;
	t_hit	closest_hit;
	t_hit	hit;

	closest_d = 10000.0;
	closest_hit.d = -1.0;
	while (objects)
	{
		hit = objects->check_ray_collison(ray, *objects);
		if (hit.d >= 0.0 && hit.d < closest_d)
		{
			closest_d = hit.d;
			closest_hit = hit;
			closest_hit.obj = objects;
		}
		objects = objects->next;
	}
	return (closest_hit);
}

static unsigned int	get_rgb(int r, int g, int b)
{
	if (r > 0xFF)
		r = 0xFF;
	if (g > 0xFF)
		g = 0xFF;
	if (b > 0xFF)
		b = 0xFF;
	return (0x00 << 24 | r << 16 | g << 8 | b);
}

t_vec3	set_diffuse(t_object *obj, t_light light, t_hit hit, t_object *obj_lst)
{
	t_ray		shadow_ray;
	t_vec3		dir2light;
	t_vec3		reflected_dir;
	double		diff;
	t_hit		shadow_hit;

	dir2light = unit_vec3(sub_vec3(light.point, hit.point));
	shadow_ray.start = add_vec3(hit.point, scale_vec3(dir2light, 0.0001));
	shadow_ray.dir = dir2light;
	shadow_hit = find_closest_collison(shadow_ray, obj_lst);
	if (shadow_hit.d > 0.0)
	{
		obj->diffuse = scale_vec3(obj->diffuse, 0.0);
		return (set_vec3(0, 0, 0));
	}
	diff = dot_vec3(dir2light, hit.normal);
	diff = (diff >= 0.0) * diff;
	obj->diffuse = scale_vec3(obj->diffuse, diff);
	reflected_dir = sub_vec3(\
		scale_vec3(hit.normal, dot_vec3(hit.normal, dir2light) * 2.0), \
		dir2light);
	return (reflected_dir);
}

int	trace_ray(t_ray ray, t_object *objects, t_light light, t_amb amb)
{
	t_hit		hit;
	t_object	obj;
	t_vec3		reflected_dir;
	double		spec;

	hit = find_closest_collison(ray, objects);
	if (hit.d < 0)
		return (\
			get_rgb(\
				amb.color.r * amb.ratio, \
				amb.color.g * amb.ratio, \
				amb.color.b * amb.ratio) \
			);
	obj = *(hit.obj);
	reflected_dir = set_diffuse(&obj, light, hit, objects);
	spec = dot_vec3(scale_vec3(ray.dir, -1.0), reflected_dir);
	spec = (spec >= 0.0) * spec;
	spec = powf(spec, 9.0);
	obj.specular = scale_vec3(obj.specular, spec * 0.8);
	obj.color = add_vec3(add_vec3(obj.amb, obj.diffuse), obj.specular);
	return (get_rgb(obj.color.r, obj.color.g, obj.color.b));
}
