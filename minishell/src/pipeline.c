/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:25:56 by jonhan            #+#    #+#             */
/*   Updated: 2023/08/11 20:22:07 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fork_heredoc(t_cmd **pipeline, t_exec *exec)
{
	pid_t	pid;
	int		status;
	int		fd;

	fd = 0;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		signal(SIGINT, c_handler);
		signal(SIGTERM, c_handler);
		signal(SIGQUIT, SIG_IGN);
		read_heredoc(pipeline, fd);
	}
	if (waitpid(-1, &status, 0) > 0)
	{
		g_error_status = WEXITSTATUS(status);
		if (g_error_status && exec->path)
			free_all(exec->path);
	}
}

int	if_pipe_error(t_cmd *iter, t_exec *exec)
{
	if (g_error_status != 0)
	{
		while (iter)
		{
			unlink_temp_files(iter);
			iter = iter->next;
		}
		return (1);
	}
	if (pipe(exec->fds_prev) < 0)
		exit(1);
	return (0);
}

void	manage_pipe(t_exec *exec)
{
	if (exec->repeat_fork > 0)
	{
		close(exec->fds_prev[0]);
		close(exec->fds_prev[1]);
	}
	if (exec->repeat_fork != 0)
	{
		exec->fds_prev[0] = exec->fds_next[0];
		exec->fds_prev[1] = exec->fds_next[1];
	}
	if (exec->repeat_fork < exec->count)
	{
		if (pipe(exec->fds_next) < 0)
			exit(1);
	}
}

void	set_child(pid_t pid, t_exec *exec, t_cmd **iter, t_list **env)
{
	if (pid == 0 && exec->repeat_fork == 0)
		first_child(*exec, *iter, env);
	else if (pid == 0 && exec->repeat_fork == exec->count - 1)
		last_child(*exec, *iter, env);
	else if (pid == 0)
		middle_child(*exec, *iter, env);
	else
	{
		exec->repeat_fork++;
		*iter = (*iter)->next;
	}
}

void	pipexline(t_cmd **pipeline, t_list **env)
{
	pid_t	pid;
	t_exec	exec;
	t_cmd	*iter;

	g_error_status = 0;
	iter = *pipeline;
	init_exec(&exec, pipeline, env);
	fork_heredoc(pipeline, &exec);
	if (if_pipe_error(iter, &exec))
		return ;
	while (exec.repeat_fork < exec.count)
	{
		manage_pipe(&exec);
		signal(SIGINT, SIG_IGN);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			send_sig();
		set_child(pid, &exec, &iter, env);
	}
	close_fd(&exec);
	wait_child(pid, exec.count);
}
