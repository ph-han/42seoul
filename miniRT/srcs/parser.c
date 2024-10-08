/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:23:07 by hcho2             #+#    #+#             */
/*   Updated: 2023/10/08 14:30:31 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_count(int *count)
{
	count[AMBIENT] = 0;
	count[CAMERA] = 0;
	count[LIGHT] = 0;
}

int	check_type(char *type, int *count)
{
	int	ret;

	if (!ft_strcmp(type, "A") && count[AMBIENT]++ == 0)
		ret = AMBIENT;
	else if (!ft_strcmp(type, "C") && count[CAMERA]++ == 0)
		ret = CAMERA;
	else if (!ft_strcmp(type, "L") && count[LIGHT]++ == 0)
		ret = LIGHT;
	else if (!ft_strcmp(type, "sp"))
		ret = SPHERE;
	else if (!ft_strcmp(type, "pl"))
		ret = PLANE;
	else if (!ft_strcmp(type, "cy"))
		ret = CYLINDER;
	else
		exit(1);
	return (ret);
}

void	nl_to_null(char *line)
{
	char	*nl;

	nl = ft_strchr(line, '\n');
	if (nl)
		*nl = '\0';
}

void	parse_input(char *filename, void *env)
{
	int		fd;
	char	*line;
	char	**splitted;
	int		count[3];
	int		type;

	init_count(count);
	fd = check_file(filename);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		nl_to_null(line);
		splitted = ft_split(line, ' ');
		free(line);
		if (!*splitted)
			continue ;
		type = check_type(splitted[0], count);
		set_value(type, splitted, env);
		free_split(splitted);
	}
	check_count(count);
}
