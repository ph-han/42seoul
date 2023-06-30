/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:18:13 by phan              #+#    #+#             */
/*   Updated: 2023/06/30 22:26:44 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./get_next_line/get_next_line.h"
# include "libft.h"
# include <stdio.h>

# define HEIGHT 900
# define WIDTH 1600

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	*r_map;
}	t_map;

typedef struct s_line
{
	double	dx;
	double	dy;
	double	step;
	double	xinc;
	double	yinc;
}	t_line;


void	put_pixel(t_img *data, int x, int y, int color);
void	ft_perror(char *e_msg);

// parse utils funcs
int		is_valid_filename(char *filename);
void	free_split(char **split_line);
int		get_map_width(char *line);
int		ft_isnum(char *data);

// parse funcs
void	parse_map(t_map *map, char *filename);

// projection funcs
void	to_isometric(t_map *map);

// rotate matrix funcs
void	rotate_x(double *x, double *y, double *z);
void	rotate_y(double *x, double *y, double *z);
void	rotate_z(double *x, double *y, double *z);

// line algo funcs
void	dda(t_img *data, t_map *map, t_point point1, t_point point2);

// map scaling funcs
void	scaling(t_map *map, double ratio);

// draw map funcs
void	draw_map_column(t_img *img, t_map *map);
void	draw_map_row(t_img *img, t_map *map);

#endif
