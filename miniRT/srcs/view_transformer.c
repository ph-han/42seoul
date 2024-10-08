/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:49:51 by hcho2             #+#    #+#             */
/*   Updated: 2023/10/12 18:44:08 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	get_obj_position(t_object *obj)
{
	return (obj->orig);
}

void	set_obj_position(t_object *obj, t_vec3 new)
{
	if (obj->type == SPHERE)
		obj->sphere.center = new;
	else if (obj->type == PLANE)
		obj->plane.point = new;
	else if (obj->type == CYLINDER)
		obj->cylinder.center = new;
}

void	view_transform(t_light *light, t_object *obj, t_cam cam)
{
	t_vec3	pos;
	t_vec3	new_obj;

	light->point = sub_vec3(light->point, cam.point);
	while (obj)
	{
		pos = get_obj_position(obj);
		new_obj = sub_vec3(pos, cam.point);
		set_obj_position(obj, new_obj);
		obj = obj->next;
	}
}
