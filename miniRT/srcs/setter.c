/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:03:02 by hcho2             #+#    #+#             */
/*   Updated: 2023/10/08 13:59:09 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_color(char *arg, t_vec3 *color)
{
	char	**splitted;

	splitted = ft_split(arg, ',');
	if (split_len(splitted) != 3)
		check_validity("Check input format!");
	color->r = ft_atof(splitted[0]);
	color->g = ft_atof(splitted[1]);
	color->b = ft_atof(splitted[2]);
	if (color->r > 255 || color->r < 0 \
		|| color->g > 255 || color->g < 0 \
		|| color->b > 255 || color->b < 0)
		check_validity("Check range!");
	free_split(splitted);
}

void	set_point(char *arg, t_vec3 *point)
{
	char	**splitted;

	splitted = ft_split(arg, ',');
	if (split_len(splitted) != 3)
		check_validity("Check input format!");
	point->x = ft_atof(splitted[0]);
	point->y = ft_atof(splitted[1]);
	point->z = ft_atof(splitted[2]);
	free_split(splitted);
}

void	check_args_count(int type, char **args)
{
	if (type == AMBIENT)
	{
		if (split_len(args) != 3)
			check_validity("Check input format!");
	}
	else if (type == CYLINDER)
	{
		if (split_len(args) != 6)
			check_validity("Check input format!");
	}
	else
	{
		if (split_len(args) != 4)
			check_validity("Check input format!");
	}
}

void	set_value(int type, char **args, t_rt *rt)
{
	check_args_count(type, args);
	if (type == AMBIENT)
		set_ambient(args, &rt->amb);
	else if (type == CAMERA)
		set_camera(args, &rt->cam);
	else if (type == LIGHT)
		set_light(args, &rt->light);
	else
		set_object(type, args, rt);
}
