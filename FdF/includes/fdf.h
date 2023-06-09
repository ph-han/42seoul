/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:18:13 by phan              #+#    #+#             */
/*   Updated: 2023/07/07 20:26:26 by phan             ###   ########.fr       */
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

# define HEIGHT 1000
# define WIDTH 1600

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
	long	color;
}	t_point;

typedef struct s_angle
{
	double	alpha;
	double	beta;
	double	gamma;
}	t_angle;

typedef struct s_map
{
	int		width;
	int		height;
	double	ratio;
	int		move_x;
	int		move_y;
	t_point	*o_map;
	t_point	*r_map;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	t_img	*img;
	t_map	*map;
	t_angle	*angle;
}	t_fdf;

typedef struct s_line
{
	double	dx;
	double	dy;
	double	step;
	double	xinc;
	double	yinc;
	double	cinc;
}	t_line;

// init funcs
void	init_angle(t_angle *angle);
void	init_map(t_map *map);
void	init_fdf(t_fdf *fdf);
void	init_img(t_fdf *fdf);

// utils
void	ft_perror(char *e_msg);
void	ft_mapcpy(t_point *r_map, t_point *o_map, int map_size);
int		close_win(t_fdf *fdf);
int		fdf_atoi(const char *str);

// check funcs
int		is_valid_filename(char *filename);
int		is_vaild_num(char *data);
int		is_valid_data(char *data);
long	check_and_set_color(char *color);

// parse utils funcs
void	free_split(char **split_line);
int		get_map_width(char *line);
int		fdf_strlen(char *s);
int		ft_find(char *hex, char c);

// parse funcs
void	parse_map(t_map *map, char *filename);

// projection funcs
void	to_isometric(t_map *map, t_angle *angle);
void	to_plan(t_fdf *fdf);

// rotate matrix funcs
void	rotate_x(t_point *point, t_angle *angle);
void	rotate_y(t_point *point, t_angle *angle);
void	rotate_z(t_point *point, t_angle *angle);

// line algo funcs
void	dda(t_img *data, t_map *map, t_point point1, t_point point2);

// map scaling funcs
void	scaling(t_map *map);

// draw map funcs
void	put_pixel(t_img *data, int x, int y, int color);
void	draw_map_column(t_img *img, t_map *map);
void	draw_map_row(t_img *img, t_map *map);
void	draw_map(t_fdf *fdf);

#endif
