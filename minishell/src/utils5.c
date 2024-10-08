/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:50:33 by phan              #+#    #+#             */
/*   Updated: 2023/08/14 16:19:39 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_empty_node(t_list **token_list)
{
	t_list	*iter;

	iter = *token_list;
	while (iter)
	{
		if (ft_strlen(iter->content) == 0)
			ft_lstdel_mid(token_list, iter);
		iter = iter->next;
	}
}

void	print_execve_error(char *simple_cmd, char *msg, int err_status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(simple_cmd, 2);
	ft_putendl_fd(msg, 2);
	exit(err_status);
}

void	print_access_error(char *valid_cmd, int err_status)
{
	ft_putstr_fd("minishell: ", 2);
	perror(valid_cmd);
	exit(err_status);
}

int	ft_indexof(char *str, char find_c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == find_c)
			return (i);
		i++;
	}
	return (-1);
}

int	set_pathname(char *simple_cmd, char **pathname, t_list **environ)
{
	if (simple_cmd)
		*pathname = ft_strdup(simple_cmd);
	else
	{
		*pathname = ft_getenv(environ, "HOME");
		if (*pathname == NULL)
		{
			print_cd_err("HOME", "not set");
			free(*pathname);
			return (1);
		}
	}
	return (0);
}
