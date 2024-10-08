/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:17:15 by hcho2             #+#    #+#             */
/*   Updated: 2023/10/12 18:37:19 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_vec3	screen2view(t_cam cam, int x, int y)
{
	t_vec3	exchange_point;

	cam.x_axis = scale_vec3(cam.axis[0], cam.fov * 2.0 * cam.ratio);
	cam.y_axis = scale_vec3(cam.axis[1], cam.fov * 2.0);
	cam.left_top = add_vec3(scale_vec3(cam.x_axis, -0.5), \
		scale_vec3(cam.y_axis, 0.5));
	cam.left_top = add_vec3(cam.axis[2], cam.left_top);
	cam.change_x = div_vec3(cam.x_axis, WIDTH);
	cam.change_y = div_vec3(cam.y_axis, HEIGHT);
	exchange_point = add_vec3(cam.left_top, scale_vec3(cam.change_x, x));
	exchange_point = add_vec3(exchange_point, scale_vec3(cam.change_y, -1 * y));
	return (exchange_point);
}

void	render_world(t_env env)
{
	t_ray	ray;
	int		x;
	int		y;

	ft_memset(env.img.addr, 0, WIDTH * HEIGHT * (env.img.bits_per_pixel / 8));
	view_transform(&env.rt.light, env.rt.objs, env.rt.cam);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray.start = screen2view(env.rt.cam, x, y);
			ray.dir = unit_vec3(ray.start);
			ray.start = scale_vec3(ray.start, 0);
			put_pixel(&env.img, x, y, \
				trace_ray(ray, env.rt.objs, env.rt.light, env.rt.amb));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
}
