/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:38:14 by phan              #+#    #+#             */
/*   Updated: 2023/08/14 18:05:45 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>

# define SYNTAX_SUCCESS	0
# define SYNTAX_ERROR	258
# define SYNTAX_ERROR_MSG "minishell: syntax error near unexpected token: "

int	g_error_status;

enum	e_type
{
	GRT,
	D_GRT,
	LSR,
	D_LSR,
	PIPE,
	WORD
};

typedef struct s_token
{
	enum e_type		type;
	char			*content;
	char			*temp;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_cmd
{
	char			**simple_cmd;
	t_token			*redir_header;
	int				io_fd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_exec
{
	int		repeat_fork;
	int		count;
	int		fds_prev[2];
	int		fds_next[2];
	char	**path;
}	t_exec;

typedef struct s_exp_var
{
	char	*str;
	int		key_size;
	int		q_flag;
	int		i;
}	t_exp_var;

/**
 * parse functions
*/
void	hello_minishell(void);
t_list	*dup_envp(char **envp);
int		is_redir(t_list *iter);

// tokenize
int		tokenizer(char *input, t_list **token_list, int flag);

// expand
void	expand_env(t_list **token_list, t_list **environ, int exp_flag);
void	expansion(t_list *node, char *content, int *idx, t_list **environ);
void	expand_tokenize_and_insert(t_list *iter, t_list **environ, int *i);
int		process_quoted_sections(t_list *iter, t_list **environ, \
	int *flag, int *i);
void	parse_expand_tokens(t_list *iter, t_list **environ, \
	int *exp_flag, int i);
char	*set_env_var(t_list **environ, char *str, int key_size);
void	set_q_flag(int *q_flag, int quote);
void	process_var_extraction_and_replacement(t_list **environ, \
	char *content, t_exp_var *var);
void	process_env_var_value_extraction(char *content, \
	t_exp_var *var);
void	process_q_flag(char *content, t_exp_var *var);

// struct_cmd
void	redir_type(t_token **type_list, t_token *node);
char	**make_simple_cmd(t_token *word_list);
void	insert_cmd_into_pipeline(t_cmd **cmd, \
	t_token **word_list, t_cmd **pipeline);
void	insert_word_into_list(t_token **list, \
	int type, char *content);
void	handle_word_insertion(t_token *iter, \
	t_token **word_list, t_cmd **cmd, t_cmd **pipeline);

void	dequotenize(t_token **type_list);

// sysntax_error
void	identify_token_type(t_list **lst, t_token **token_lst);
int		syntax_error(t_token **type_list);
int		ft_error(t_token **type_list, char *content);

// utils
t_token	*ft_token_new(int type, void *content);
void	ft_tokenadd_back(t_token **lst, t_token *new);
void	ft_tokendelone(t_token *lst, void (*del)(void *));
void	ft_tokendel_mid(t_token **lst, t_token *node);
void	ft_tokenclear(t_token **lst, void (*del)(void *));

// utils2
t_cmd	*ft_cmd_new(void);
void	ft_cmdadd_back(t_cmd **lst, t_cmd *new);
void	ft_cmdclear(t_cmd **lst, void (*del)(void *));
void	sigterm_exit(void);

// utils3
int		is_delim_in_dquote(char c);
int		is_delim(char c);
int		ft_is_blank(int c);
int		check_num(char *str);
char	**free_all(char **w_list);

// utils 4
void	make_token(char *input, t_list **token_list, int token_size);
char	*ft_lst_strjoin(t_list **lst);
int		ft_atouc(char *str, unsigned char *num);
int		ft_strcmp(char *s1, char *s2);
char	*ft_getenv(t_list **environ, char *word);

// utils 5
void	delete_empty_node(t_list **token_list);
void	print_execve_error(char *simple_cmd, char *msg, int err_status);
void	print_access_error(char *valid_cmd, int error_status);
int		ft_indexof(char *str, char find_c);
int		set_pathname(char *simple_cmd, char **pathname, t_list **environ);
void	print_cd_err(char *path, char *str);

/**
 * built-in functions
*/
void	ft_export(char **simple_cmd, t_list **environ, int fd);
void	ft_cd(char **simple_cmd, t_list **environ, int fd);
void	ft_pwd(char **simple_cmd, t_list **environ, int fd);
void	ft_unset(char **simple_cmd, t_list **environ, int fd);
void	ft_exit(char **simple_cmd, t_list **environ, int fd);
void	ft_env(char **simple_cmd, t_list **environ, int fd);
void	ft_echo(char **simple_cmd, t_list **environ, int fd);
t_list	*ft_getenvnode(t_list **environ, char *word);
int		is_invalid_key(int c);
int		print_export_err(char *str);
char	*make_word(char *str);
int		is_valid_export_arg(char *str, char *simple_cmd);
void	print_export_list(t_list **environ, int fd);

/**
 * execute functions
*/
int		is_built_in(char **simple_cmd);
int		run_cmd(t_cmd *cmd, t_list **environ, int flag, int is_p);

//heredoc
void	change_heredoc(t_cmd **pipeline);
void	read_heredoc(t_cmd **pipeline, int fd);
void	unlink_temp_files(t_cmd *cmd);
int		init_redir(t_cmd *cmd);

//pipexline
void	first_child(t_exec arg, t_cmd *cmd, t_list **env);
void	middle_child(t_exec arg, t_cmd *cmd, t_list **env);
void	last_child(t_exec arg, t_cmd *cmd, t_list **env);
void	wait_child(pid_t pid, int count);
void	evecve_error(char *valid_cmd, char *simple_cmd);
char	**make_envp(t_list **env);
void	redir_error(t_cmd *cmd);
void	run_built_in(t_cmd *cmd, t_list **env);
void	close_fd_and_unlink(t_exec *arg, t_cmd *cmd);

//pipexutil
void	init_exec(t_exec *exec, t_cmd **pipeline, t_list **env);
void	close_fd(t_exec *arg);
int		count_pipe(t_cmd **pipeline);
t_cmd	*struct_cmd(t_token **type_list);
char	**detec_path(t_list **environ);
void	while_pipe(t_cmd **pipeline);
void	pipexline(t_cmd **pipeline, t_list **env);
char	*valid(char **path, char *command);
void	send_sig(void);

// signal
void	p_handler(int sig);
void	c_handler(int sig);

#endif
