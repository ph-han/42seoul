/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:00:00 by phan              #+#    #+#             */
/*   Updated: 2023/07/04 13:09:57 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_perror(char *e_msg)
{
	ft_putendl_fd(e_msg, 2);
	exit(0);
}

void	close_win(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

void	ft_mapdup(t_point *r_map, t_point *o_map, int map_size)
{
	int	i;

	i = -1;
	while (++i < map_size)
		o_map[i] = r_map[i];
}

int	is_valid_filename(char *filename)
{
	char	**filename_split;
	int		wc;

	filename_split = ft_split(filename, '.');
	wc = 0;
	while (filename_split[wc++])
		;
	if (wc <= 2)
		return (0);
	if (ft_strncmp(filename_split[wc - 2], "fdf", 4) != 0)
	{
		free_split(filename_split);
		return (0);
	}
	free_split(filename_split);
	return (1);
}
