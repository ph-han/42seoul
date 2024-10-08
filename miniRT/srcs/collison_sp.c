/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collison_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:15:07 by phan              #+#    #+#             */
/*   Updated: 2023/10/02 12:03:56 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	get_distance(double b, double nabla)
{
	double	d1;
	double	d2;

	d1 = -b + sqrtf(nabla);
	d2 = -b - sqrtf(nabla);
	return (((d1 < d2) * d1) + ((d1 >= d2) * d2));
}

t_hit	check_ray_collison_sphere(t_ray ray, t_object obj)
{
	t_hit	hit;
	t_vec3	tmp;
	double	b;
	double	c;
	double	nabla;

	hit.d = -1.0;
	tmp = sub_vec3(ray.start, obj.sphere.center);
	b = dot_vec3(ray.dir, tmp);
	c = dot_vec3(tmp, tmp) - obj.sphere.radius * obj.sphere.radius;
	nabla = b * b - c;
	if (nabla >= 0.0)
	{
		hit.d = get_distance(b, nabla);
		hit.point = add_vec3(ray.start, scale_vec3(ray.dir, hit.d));
		hit.normal = unit_vec3(sub_vec3(hit.point, obj.sphere.center));
	}
	return (hit);
}
