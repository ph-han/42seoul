/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:50:22 by phan              #+#    #+#             */
/*   Updated: 2023/10/08 14:31:31 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	*new_obj(void)
{
	t_object	*tmp;

	tmp = (t_object *)malloc(sizeof(t_object));
	if (!tmp)
		exit(1);
	tmp->next = NULL;
	return (tmp);
}

void	obj_lstadd_back(t_object **lst, t_object *new)
{
	t_object	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_split(char **split_line)
{
	int	idx;

	idx = 0;
	while (split_line[idx])
		free(split_line[idx++]);
	free(split_line);
}

void	check_count(int *count)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (count[i++] == 0)
			check_validity("Missing element(s)!");
	}
}

int	check_file(char *filename)
{
	int		fd;
	int		len;
	char	**splitted;

	splitted = ft_split(filename, '.');
	len = 0;
	while (splitted[len])
		len++;
	if (len != 2)
		check_validity("Wrong file name!");
	if (ft_strcmp(splitted[1], "rt"))
		check_validity("Wrong file name!");
	free_split(splitted);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		check_validity("File open error!");
	return (fd);
}
