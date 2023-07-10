/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:00:00 by phan              #+#    #+#             */
/*   Updated: 2023/07/10 13:09:06 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_perror(char *e_msg)
{
	ft_putendl_fd(e_msg, 2);
	exit(0);
}

int	fdf_atoi(char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign * result) > 10000000 || (sign * result) < -10000000)
			ft_perror("Data is over 10000000 or -10000000");
		str++;
	}
	return ((int)(sign * result));
}

void	ft_mapcpy(t_point *r_map, t_point *o_map, int map_size)
{
	int	i;

	i = -1;
	while (++i < map_size)
		o_map[i] = r_map[i];
}

int	close_win(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
	return (0);
}

void	free_split(char **split_line)
{
	int	idx;

	idx = 0;
	while (split_line[idx])
		free(split_line[idx++]);
	free(split_line);
}
