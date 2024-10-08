/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:43:52 by phan              #+#    #+#             */
/*   Updated: 2023/10/08 13:51:02 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3
{
	union
	{
		struct
		{
			double	x;
			double	y;
			double	z;
		};
		struct
		{
			double	r;
			double	g;
			double	b;
		};
		double	pos[3];
	};
}	t_vec3;

/* vec3 */
double	sqrlen_vec3(t_vec3 v);
double	len_vec3(t_vec3 v);
t_vec3	add_vec3(t_vec3 u, t_vec3 v);
t_vec3	sub_vec3(t_vec3 u, t_vec3 v);
t_vec3	scale_vec3(t_vec3 v, double t);
t_vec3	div_vec3(t_vec3 v, double t);
double	dot_vec3(t_vec3 u, t_vec3 v);
t_vec3	cross_vec3(t_vec3 u, t_vec3 v);
t_vec3	unit_vec3(t_vec3 v);
t_vec3	set_vec3(double x, double y, double z);

#endif
