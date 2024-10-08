/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collison_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:15:05 by phan              #+#    #+#             */
/*   Updated: 2023/10/07 14:58:50 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	check_ray_plane(t_ray ray, t_plane plane, t_vec3 *point, double *t)
{
	if (dot_vec3(plane.normal, scale_vec3(ray.dir, -1)) < 0.0)
		return (0);
	if (fabs(dot_vec3(plane.normal, ray.dir)) < 1e-2)
		return (0);
	*t = (dot_vec3(plane.point, plane.normal) \
		- dot_vec3(plane.normal, ray.start)) \
		/ dot_vec3(ray.dir, plane.normal);
	if (*t < 0.0)
		return (0);
	*point = add_vec3(ray.start, scale_vec3(ray.dir, *t));
	return (1);
}

t_hit	check_ray_collison_plane(t_ray ray, t_object obj)
{
	t_hit	hit;
	t_vec3	point;
	double	t;

	hit.d = -1.0;
	if (check_ray_plane(ray, obj.plane, &point, &t))
	{
		hit.d = t;
		hit.point = point;
		hit.normal = obj.plane.normal;
	}
	return (hit);
}
