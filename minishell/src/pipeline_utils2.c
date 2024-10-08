/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:34:07 by phan              #+#    #+#             */
/*   Updated: 2023/08/10 11:26:30 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipe(t_cmd **pipeline)
{
	t_cmd	*iter;
	int		cnt;

	cnt = 0;
	iter = *pipeline;
	while (iter)
	{
		cnt++;
		iter = iter->next;
	}
	return (cnt);
}

char	**detec_path(t_list **environ)
{
	t_list	*iter;
	char	**res;

	iter = *environ;
	res = NULL;
	while (iter)
	{
		if (!ft_strncmp(iter->content, "PATH=", 5))
			res = ft_split((iter->content) + 5, ':');
		iter = iter->next;
	}
	return (res);
}

char	*valid(char **path, char *command)
{
	char	*tmp;
	char	*path_cmd;
	int		i;

	i = 0;
	if (ft_strchr(command, '/'))
		return (ft_strdup(command));
	else
	{
		path_cmd = ft_strjoin("/", command);
		while (path && path[i])
		{
			tmp = ft_strjoin(path[i], path_cmd);
			if (access(tmp, F_OK) > -1)
			{
				free(path_cmd);
				return (tmp);
			}
			free(tmp);
			i++;
		}
	}
	free(path_cmd);
	return (NULL);
}
