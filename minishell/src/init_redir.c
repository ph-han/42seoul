/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:18:58 by phan              #+#    #+#             */
/*   Updated: 2023/08/13 14:30:38 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_lsr(t_cmd *cmd, t_token *redir_iter)
{
	if (cmd->io_fd[0] != 0)
		close(cmd->io_fd[0]);
	cmd->io_fd[0] = open(redir_iter->content, O_RDONLY);
	if (cmd->io_fd[0] < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(redir_iter->content);
		return (1);
	}
	return (0);
}

int	redir_grt(t_cmd *cmd, t_token *redir_iter)
{
	if (cmd->io_fd[1] != 1)
		close(cmd->io_fd[1]);
	cmd->io_fd[1] = \
		open(redir_iter->content, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cmd->io_fd[1] < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(redir_iter->content);
		return (1);
	}
	return (0);
}

int	redit_d_grt(t_cmd *cmd, t_token *redir_iter)
{
	if (cmd->io_fd[1] != 1)
		close(cmd->io_fd[1]);
	cmd->io_fd[1] = \
		open(redir_iter->content, O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (cmd->io_fd[1] < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(redir_iter->content);
		return (1);
	}
	return (0);
}

int	init_redir(t_cmd *cmd)
{
	t_token	*redir_iter;
	int		type;

	redir_iter = cmd->redir_header;
	while (redir_iter)
	{
		type = redir_iter->type;
		if (type == LSR || type == D_LSR)
		{
			if (redir_lsr(cmd, redir_iter) == 1)
				return (1);
		}
		else if (type == GRT)
		{
			if (redir_grt(cmd, redir_iter) == 1)
				return (1);
		}
		else if (type == D_GRT)
		{
			if (redit_d_grt(cmd, redir_iter) == 1)
				return (1);
		}
		redir_iter = redir_iter->next;
	}
	return (0);
}

void	while_pipe(t_cmd **pipeline)
{
	t_cmd	*iter;

	iter = *pipeline;
	while (iter)
	{
		printf("<pipe 1>\n");
		init_redir(iter);
		iter = iter->next;
	}
}
