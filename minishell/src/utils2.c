/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:20:36 by phan              #+#    #+#             */
/*   Updated: 2023/08/13 14:31:41 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_cmd_new(void)
{
	t_cmd	*tmp;

	tmp = (t_cmd *)malloc(sizeof(t_cmd));
	if (!tmp)
		exit(1);
	tmp->io_fd[0] = 0;
	tmp->io_fd[1] = 1;
	tmp->simple_cmd = NULL;
	tmp->redir_header = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void	ft_cmdadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_cmdclear(t_cmd **lst, void (*del)(void *))
{
	t_cmd	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		ft_tokenclear(&((*lst)->redir_header), del);
		free_all((*lst)->simple_cmd);
		*lst = tmp->next;
		free(tmp);
	}
	lst = NULL;
}

void	sigterm_exit(void)
{
	ft_putendl_fd("exit", 1);
	exit(g_error_status);
}
