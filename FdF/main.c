/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:54 by phan              #+#    #+#             */
/*   Updated: 2023/07/01 20:28:18 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

/*
	To-Do list (7.2 ~ 7.3)
	1. 각 구조체 초기화 함수
	2. 마우스 휠 : scaling (구조체에 ratio변수 생성 후) 버튼 누를 때마다 0.5씩 증가 혹은 감소
	3-1. q, w, e 버튼 각각 x, y, z 축 회전 (각 회전각도 구조체에 선언 해야댐) 누를 때 마다 0.5씩 각각 각도 변환 (증가)
	3-2. a, s, d 버튼 각각 x, y, z 축 회전 (각 회전각도 구조체에 선언 해야댐) 누를 때 마다 0.5씩 각각 각도 변환 (감소)
	3-3. 시간이 되면 드래그를 기반으로 축 회전
	4. 방향키로 화면 이동 좌표 (0.8씩 이동)
	5. 함수 정리
*/

void	ft_perror(char *e_msg)
{
	ft_putendl_fd(e_msg, 2);
	exit(1);
}

void	close_win(t_fdf *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}


void rotate_map_x(t_fdf *fdf)
{
	int i;

	i = 0;
	// printf("map size : %d %d\n", fdf->map->width, fdf->map->width);
	while (i < (fdf->map->height) * (fdf->map->width))
	{
		// rotate_z(&(fdf->map->r_map[i].x), &(fdf->map->r_map[i].y), &(fdf->map->r_map[i].z), -0.8);
		rotate_x(&(fdf->map->r_map[i].x), &(fdf->map->r_map[i].y), &(fdf->map->r_map[i].z), -0.5);
		i++;
	}
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	fdf->img->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel, &fdf->img->line_length, &fdf->img->endian);
	draw_map_column(fdf->img, fdf->map);
	draw_map_row(fdf->img, fdf->map);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}

void rotate_map_y(t_fdf *fdf)
{
	int i;

	i = 0;
	// printf("map size : %d %d\n", fdf->map->width, fdf->map->width);
	while (i < (fdf->map->height) * (fdf->map->width))
	{
		// rotate_all(&(fdf->map->r_map[i].x), &(fdf->map->r_map[i].y), &(fdf->map->r_map[i].z), -0.5);
		rotate_y(&(fdf->map->r_map[i].x), &(fdf->map->r_map[i].y), &(fdf->map->r_map[i].z), -0.5);
		i++;
	}
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	fdf->img->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel, &fdf->img->line_length, &fdf->img->endian);
	draw_map_column(fdf->img, fdf->map);
	draw_map_row(fdf->img, fdf->map);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}

int hooks(int key_code, t_fdf *fdf)
{
	printf("code : %d\n", key_code);
	if (key_code == 53)
		close_win(fdf);
	if (key_code == 18) // up
		rotate_map_x(fdf);
	else if (key_code == 19) // down
		rotate_map_y(fdf);
	else if (key_code == 1)
		scaling(fdf->map, );
	return (0);
}

void	check_leaks(void)
{
	system("leaks fdf");
}

int main(int ac, char *av[])
{
	t_fdf	fdf;

	// atexit(check_leaks);
	if (ac != 2)
		return (0);
	if (!is_valid_filename(av[1]))
		ft_perror("Invalid filename!");
	fdf.map = (t_map *)malloc(sizeof(t_map));
	fdf.img = (t_img *)malloc(sizeof(t_img));
	parse_map(fdf.map, av[1]);
	to_isometric(fdf.map);
	scaling(fdf.map, 6 / 10.0);
	printf("scaling ok\n");
	fdf.mlx = mlx_init();
	if (!fdf.mlx)
		write(1, "mlx error\n", 11);
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "TEST");
	fdf.img->img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	fdf.img->addr = mlx_get_data_addr(fdf.img->img, &fdf.img->bits_per_pixel, &fdf.img->line_length, &fdf.img->endian);
	draw_map_column(fdf.img, fdf.map);
	draw_map_row(fdf.img, fdf.map);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img->img, 0, 0);
	mlx_hook(fdf.win, 2, 1L << 0, hooks, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
