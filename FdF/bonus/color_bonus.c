/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:55:17 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 12:25:17 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	get_r(long color)
{
	unsigned int	a;

	a = color >> 24;
	color = (color ^ (a << 24));
	return (color >> 16);
}

int	get_g(long color)
{
	unsigned int	ar;

	ar = color >> 16;
	color = (color ^ (ar << 16));
	return (color >> 8);
}

int	get_b(long color)
{
	unsigned int	arg;

	arg = color >> 8;
	color = (color ^ (arg << 8));
	return (color);
}

int	get_a(long color)
{
	return (color >> 24);
}

unsigned int	gradation(long color1, long color2, double cinc)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = get_a(color1) * cinc + (1 - cinc) * get_a(color2);
	r = get_r(color1) * cinc + (1 - cinc) * get_r(color2);
	g = get_g(color1) * cinc + (1 - cinc) * get_g(color2);
	b = get_b(color1) * cinc + (1 - cinc) * get_b(color2);
	return (a << 24 | r << 16 | g << 8 | b);
}
