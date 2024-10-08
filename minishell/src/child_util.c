/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:09:54 by phan              #+#    #+#             */
/*   Updated: 2023/08/10 12:09:55 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_error(t_cmd *cmd)
{
	unlink_temp_files(cmd);
	exit(1);
}

void	run_built_in(t_cmd *cmd, t_list **env)
{
	run_cmd(cmd, env, is_built_in(cmd->simple_cmd), 0);
	exit(g_error_status);
}

void	close_fd_and_unlink(t_exec *arg, t_cmd *cmd)
{
	close(arg->fds_next[0]);
	close(arg->fds_next[1]);
	unlink_temp_files(cmd);
}
