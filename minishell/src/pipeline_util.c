/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:26:46 by jonhan            #+#    #+#             */
/*   Updated: 2023/08/13 14:31:28 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_exec(t_exec *exec, t_cmd **pipeline, t_list **env)
{
	exec->count = count_pipe(pipeline);
	exec->repeat_fork = 0;
	exec->path = detec_path(env);
}

void	close_fd(t_exec *arg)
{
	close(arg->fds_prev[0]);
	close(arg->fds_prev[1]);
	if (arg->count > 0)
	{
		close(arg->fds_next[1]);
		close(arg->fds_next[0]);
	}
	if (arg->path)
		free_all(arg->path);
}

void	send_sig(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	evecve_error(char *valid_cmd, char *simple_cmd)
{
	if (valid_cmd)
	{
		if (access(valid_cmd, F_OK) < 0)
			print_access_error(valid_cmd, 127);
		else if (access(valid_cmd, X_OK) < 0)
			print_access_error(valid_cmd, 126);
		else if (opendir(valid_cmd) != 0)
		{
			if (ft_strchr(valid_cmd, '/'))
				print_execve_error(valid_cmd, ": is a directory", 126);
			else
				print_execve_error(valid_cmd, ": command not found", 127);
		}
		else
			exit(0);
	}
	else
		print_execve_error(simple_cmd, ": command not found", 127);
}
