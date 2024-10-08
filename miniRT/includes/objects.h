/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:46:36 by phan              #+#    #+#             */
/*   Updated: 2023/10/08 14:07:11 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec3.h"
# include "hit.h"
# include "ray.h"

enum	e_type
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
};

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	normal;
	double	diameter;
	double	height;
}	t_cylinder;

typedef struct s_obj_exp_var
{
	double	a;
	double	b;
	double	c;
	double	nabla;
	double	vdot;
	t_vec3	vsub;
}	t_obj_exp_var;

typedef struct s_object
{
	enum e_type		type;
	t_vec3			amb;
	t_vec3			diffuse;
	t_vec3			specular;
	t_vec3			color;
	t_vec3			orig;
	t_plane			plane;
	t_sphere		sphere;
	t_cylinder		cylinder;
	t_hit			(*check_ray_collison)(t_ray, struct s_object);
	struct s_object	*next;
}	t_object;

// sphere
t_hit	check_ray_collison_sphere(t_ray ray, t_object obj);

// plane
t_hit	check_ray_collison_plane(t_ray ray, t_object obj);

// cylinder
t_hit	check_ray_collison_cylinder(t_ray ray, t_object obj);

/* collison cy utils */
int		is_over_cylinder_range(double h, double max);
double	get_side_distance(double a, double b, double nabla);
double	get_base_distance(t_ray ray, t_cylinder cy, double *d1, double *d2);
void	init_cy_exp_var(t_ray ray, t_cylinder cy, t_obj_exp_var *var);

#endif
