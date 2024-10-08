/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:55:31 by phan              #+#    #+#             */
/*   Updated: 2023/08/11 16:47:10 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*set_env_var(t_list **environ, char *str, int key_size)
{
	char	*env;
	char	*error_status;
	char	*tmp;

	env = ft_getenv(environ, str);
	tmp = ft_substr(str, 1, ft_strlen(str));
	error_status = ft_itoa(g_error_status);
	if (env == NULL && !ft_strncmp(str, "?", 1))
		env = ft_strjoin(error_status, tmp);
	else if (env == NULL && key_size != 0)
		env = ft_strdup("");
	else if (env == NULL && key_size == 0)
		env = ft_strdup("$");
	free(str);
	free(tmp);
	free(error_status);
	return (env);
}

void	set_q_flag(int *q_flag, int quote)
{
	if (*q_flag == 0)
		*q_flag = quote;
	else if (*q_flag == quote)
		*q_flag = 0;
}

void	process_var_extraction_and_replacement(t_list **environ, \
	char *content, t_exp_var *var)
{
	var->i++;
	while (content[var->i + var->key_size] && \
		!is_delim(content[var->i + var->key_size]))
	{
		if (var->q_flag == '\"' && \
		(ft_is_blank(content[var->i + var->key_size]) || \
		content[var->i + var->key_size] == '$'))
			break ;
		var->key_size++;
	}
	var->str = ft_substr(content, var->i, var->key_size);
	var->str = set_env_var(environ, var->str, var->key_size);
	var->i += var->key_size;
}

void	process_env_var_value_extraction(char *content, t_exp_var *var)
{
	while (content[var->i + var->key_size] && \
		!ft_strchr("\'\"", content[var->i + var->key_size]))
	{
		if (var->q_flag != '\'' && \
			content[var->i + var->key_size] == '$')
			break ;
		var->key_size++;
	}
	var->str = ft_substr(content, var->i, var->key_size);
	var->i += var->key_size;
}

void	process_q_flag(char *content, t_exp_var *var)
{
	if (content[var->i + var->key_size] == '\'')
	{
		set_q_flag(&var->q_flag, '\'');
		var->str = ft_strdup("\'");
		var->i++;
	}
	else if (content[var->i + var->key_size] == '\"')
	{
		set_q_flag(&var->q_flag, '\"');
		var->str = ft_strdup("\"");
		var->i++;
	}
}
