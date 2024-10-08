/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:43:02 by phan              #+#    #+#             */
/*   Updated: 2023/08/14 16:22:04 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parse(char **input, t_list **token_list, \
	t_token **type_list, t_list **environ)
{
	if (*(*input))
		add_history(*input);
	if (!*(*input) || tokenizer(*input, token_list, 0) == 1)
	{
		ft_lstclear(token_list, free);
		free(*input);
		return (1);
	}
	expand_env(token_list, environ, 0);
	identify_token_type(token_list, type_list);
	free(*input);
	if (syntax_error(type_list) == SYNTAX_ERROR)
		return (1);
	dequotenize(type_list);
	return (0);
}

static void	execute(t_cmd **pipeline, t_list **environ)
{
	int	built_in_idx;

	if (!*pipeline)
		return ;
	change_heredoc(pipeline);
	built_in_idx = is_built_in((*pipeline)->simple_cmd);
	if (count_pipe(pipeline) == 1 && built_in_idx > -1)
	{
		if (init_redir(*pipeline) == 1)
		{
			unlink_temp_files(*pipeline);
			exit(1);
		}
		if (built_in_idx == 0)
			ft_putendl_fd("exit", STDOUT_FILENO);
		run_cmd(*pipeline, environ, is_built_in((*pipeline)->simple_cmd), 1);
	}
	else
		pipexline(pipeline, environ);
}

static void	minishell_start(char **envp, t_list **environ, \
	t_list **token_list, t_token **type_list)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	*token_list = NULL;
	*type_list = NULL;
	*environ = dup_envp(envp);
	hello_minishell();
}

int	main(int ac, char **av, char **envp)
{
	char	*input;
	t_list	*environ;
	t_list	*token_list;
	t_token	*type_list;
	t_cmd	*pipeline;

	(void)ac;
	(void)av;
	minishell_start(envp, &environ, &token_list, &type_list);
	while (1)
	{
		signal(SIGINT, p_handler);
		signal(SIGQUIT, SIG_IGN);
		input = readline("parshell-1.8 % ");
		if (!input)
			sigterm_exit();
		if (parse(&input, &token_list, &type_list, &environ))
			continue ;
		pipeline = struct_cmd(&type_list);
		execute(&pipeline, &environ);
		ft_cmdclear(&pipeline, free);
		ft_tokenclear(&type_list, free);
	}
	return (g_error_status);
}
