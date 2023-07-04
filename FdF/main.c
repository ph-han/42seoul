/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:39:54 by phan              #+#    #+#             */
/*   Updated: 2023/07/04 13:44:22 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * To-Do list (7.4 ~ 7.5)
 * 1. norm 맞추기 (hooks, parse)
 * 2. 다른 projection 방식 적용
 * 3. 그라데이션 or 높이 변경 적용
 * 4. input program 테스트
 * 5. 코드정리
 * 
*/

int	restore(t_fdf *fdf)
{
	ft_mapdup(fdf->map->o_map, fdf->map->r_map, fdf->map->width * fdf->map->height);
	to_isometric(fdf->map, fdf->angle);
	scaling(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	draw_map(fdf);
	return (0);
}

int k_hooks(int key_code, t_fdf *fdf)
{
	printf("key_code : %d\n", key_code);
	if (key_code == 53) // esc
		close_win(fdf);
	if (key_code == 18) // 1
		rotate_map_x(fdf, 0.05);
	else if (key_code == 19) // 2
		rotate_map_x(fdf, -0.05);
	else if (key_code == 20) // 3
		rotate_map_y(fdf, 0.05);
	else if (key_code == 21) // 4
		rotate_map_y(fdf, -0.05);
	else if (key_code == 22) // 3
		rotate_map_z(fdf, 0.05);
	else if (key_code == 23) // 4
		rotate_map_z(fdf, -0.05);
	else if (key_code == 1) // s
		mlx_loop_hook(fdf->mlx, auto_rotate, fdf);
	else if (key_code == 123)
		move_left(fdf);
	else if (key_code == 124)
		move_right(fdf);
	else if (key_code == 125)
		move_down(fdf);
	else if (key_code == 126)
		move_up(fdf);
	else if (key_code == 15)
		restore(fdf);
	return (0);
}

int	m_hooks(int key_code, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (key_code == 5)
		zoom_in(fdf);
	else if (key_code == 4)
		zoom_out(fdf);
	return (0);
}

int	main(int ac, char *av[])
{
	t_fdf	fdf;

	if (ac != 2)
		return (0);
	if (!is_valid_filename(av[1]))
		ft_perror("Invalid filename!");
	init_fdf(&fdf);
	parse_map(fdf.map, av[1]);
	to_isometric(fdf.map, fdf.angle);
	scaling(fdf.map);
	fdf.mlx = mlx_init();
	if (!fdf.mlx)
		ft_perror("MLX ERROR!");
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FdF");
	draw_map(&fdf);
	mlx_mouse_hook(fdf.win, m_hooks, &fdf);
	mlx_key_hook(fdf.win, k_hooks, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
