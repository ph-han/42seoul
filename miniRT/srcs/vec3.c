/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:05:02 by hcho2             #+#    #+#             */
/*   Updated: 2023/10/07 12:06:51 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

double	sqrlen_vec3(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	len_vec3(t_vec3 v)
{
	return (sqrt(sqrlen_vec3(v)));
}

t_vec3	add_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	ret;

	ret.x = u.x + v.x;
	ret.y = u.y + v.y;
	ret.z = u.z + v.z;
	return (ret);
}

t_vec3	sub_vec3(t_vec3 u, t_vec3 v)
{
	t_vec3	ret;

	ret.x = u.x - v.x;
	ret.y = u.y - v.y;
	ret.z = u.z - v.z;
	return (ret);
}

t_vec3	div_vec3(t_vec3 v, double t)
{
	v.x *= (1 / t);
	v.y *= (1 / t);
	v.z *= (1 / t);
	return (v);
}
