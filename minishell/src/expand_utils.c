/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:47:57 by phan              #+#    #+#             */
/*   Updated: 2023/08/11 20:06:10 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(t_list *iter)
{
	return (iter->prev && \
		(!ft_strcmp(iter->prev->content, "<") || \
		!ft_strcmp(iter->prev->content, ">") || \
		!ft_strcmp(iter->prev->content, ">>")));
}

void	expand_tokenize_and_insert(t_list *iter, t_list **environ, int *i)
{
	t_list	*tmp_list;

	tmp_list = NULL;
	expansion(iter, iter->content, i, environ);
	if (!is_redir(iter))
		tokenizer(iter->content, &tmp_list, 0);
	ft_lstadd_mid(iter, &tmp_list);
	ft_lstclear(&tmp_list, free);
}

int	process_quoted_sections(t_list *iter, t_list **environ, int *flag, int *i)
{
	char	*tmp;

	tmp = iter->content;
	*flag = tmp[*i];
	while (tmp[*i] && *flag == '\'')
	{
		(*i)++;
		if (tmp[(*i)] == *flag)
		{
			*flag = 0;
			(*i)++;
		}
	}
	while (tmp[*i] && *flag == '\"')
	{
		if (tmp[*i] != '$')
			(*i)++;
		if (tmp[*i] == '$')
		{
			expand_tokenize_and_insert(iter, environ, i);
			*flag = 0;
			return (1);
		}
	}
	return (0);
}

void	parse_expand_tokens(t_list *iter, \
	t_list **environ, int *exp_flag, int i)
{
	char	*tmp;
	int		flag;

	tmp = iter->content;
	while (tmp[i])
	{
		flag = 0;
		if (tmp[i] == '\'' || tmp[i] == '\"')
		{
			*exp_flag = process_quoted_sections(iter, environ, &flag, &i);
			if (*exp_flag)
				break ;
		}
		else
		{
			if (tmp[i] == '$')
			{
				expand_tokenize_and_insert(iter, environ, &i);
				*exp_flag = 1;
				break ;
			}
			i++;
		}
	}
}
