/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collison_cy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:55:33 by phan              #+#    #+#             */
/*   Updated: 2023/10/11 14:19:41 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_over_cylinder_range(double h, double total_h)
{
	if (fabs(h) > total_h / 2.0)
		return (1);
	return (0);
}

double	get_side_distance(double a, double b, double nabla)
{
	double	d1;
	double	d2;

	d1 = (-b + sqrt(nabla)) / a;
	d2 = (-b - sqrt(nabla)) / a;
	return (((d1 < d2) * d1) + ((d1 >= d2) * d2));
}

double	get_base_distance(t_ray ray, t_cylinder cy, double *d1, double *d2)
{
	double	tmp1;
	double	tmp2;

	tmp1 = dot_vec3(cy.normal, ray.start);
	tmp2 = dot_vec3(ray.dir, cy.normal);
	*d1 = (dot_vec3(\
		add_vec3(scale_vec3(cy.normal, cy.height / 2.0), cy.center), \
		cy.normal) - \
		tmp1) / tmp2;
	*d2 = (dot_vec3(add_vec3(scale_vec3(cy.normal, -cy.height / 2.0), \
		cy.center), cy.normal) - tmp1) / tmp2;
	return (((*d1 < *d2) * *d1) + ((*d1 >= *d2) * *d2));
}

void	init_cy_exp_var(t_ray ray, t_cylinder cy, t_obj_exp_var *var)
{
	var->vsub = sub_vec3(ray.start, cy.center);
	var->vdot = dot_vec3(var->vsub, cy.normal);
	var->a = pow(dot_vec3(ray.dir, cy.normal), 2.0) - 1.0;
	var->b = \
		dot_vec3(ray.dir, cy.normal) * var->vdot - dot_vec3(var->vsub, ray.dir);
	var->c = pow(cy.diameter / 2.0, 2.0f) \
		- dot_vec3(var->vsub, var->vsub) \
		+ pow(var->vdot, 2.0);
	var->nabla = var->b * var->b - var->a * var->c;
}
