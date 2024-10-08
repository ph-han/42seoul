/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:08:59 by hcho2             #+#    #+#             */
/*   Updated: 2023/10/08 13:57:54 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_validity(char *msg)
{
	printf("Error\n");
	printf("%s\n", msg);
	exit(1);
}

int	split_len(char **p)
{
	int	len;

	len = 0;
	while (p[len])
		len++;
	return (len);
}

void	set_dir(char *arg, t_vec3 *dir)
{
	char	**splitted;

	splitted = ft_split(arg, ',');
	if (split_len(splitted) != 3)
		check_validity("Check input format!");
	dir->x = ft_atof(splitted[0]);
	dir->y = ft_atof(splitted[1]);
	dir->z = ft_atof(splitted[2]);
	if (dir->x > 1 || dir->x < -1 || \
		dir->y > 1 || dir->y < -1 || \
		dir->z > 1 || dir->z < -1)
		check_validity("Check range!");
	free_split(splitted);
}

void	set_ratio(char *arg, double	*ratio)
{
	*ratio = ft_atof(arg);
	if (*ratio < 0 || *ratio > 1)
		check_validity("Check range!");
}
