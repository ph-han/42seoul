/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:09:05 by phan              #+#    #+#             */
/*   Updated: 2023/08/11 20:25:30 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expansion(t_list *node, char *content, int *idx, t_list **environ)
{
	t_list		*lst;
	t_exp_var	var;

	lst = NULL;
	var.i = 0;
	var.q_flag = 0;
	while (content[var.i])
	{
		var.key_size = 0;
		if (content[var.i + var.key_size] == '$' && var.q_flag != '\'')
			process_var_extraction_and_replacement(environ, content, &var);
		else if (content[var.i + var.key_size] == '\'' || \
			content[var.i + var.key_size] == '\"')
			process_q_flag(content, &var);
		else
			process_env_var_value_extraction(content, &var);
		ft_lstadd_back(&lst, ft_lstnew(var.str));
	}
	*idx = var.i;
	free(node->content);
	node->content = ft_lst_strjoin(&lst);
	ft_lstclear(&lst, free);
}

void	delete_dup_node(t_list **token_list, t_list **iter, \
	t_list **iter_next, int *exp_flag)
{
	ft_lstdel_mid(token_list, (*iter)->prev);
	*iter = *iter_next;
	*exp_flag = 0;
}

int	check_d_lsr(t_list **iter)
{
	if ((*iter)->prev && !ft_strcmp("<<", (*iter)->prev->content))
	{
		*iter = (*iter)->next;
		if (!*iter)
			return (1);
	}
	return (0);
}

void	expand_env(t_list **token_list, t_list **environ, int exp_flag)
{
	t_list	*iter;
	t_list	*iter_next;

	iter = *token_list;
	while (iter)
	{
		exp_flag = 0;
		if (check_d_lsr(&iter))
			break ;
		iter_next = iter->next;
		if (ft_strchr((char *)iter->content, '$'))
			parse_expand_tokens(iter, environ, &exp_flag, 0);
		iter = iter->next;
		if ((exp_flag && iter != NULL))
		{
			if (is_redir(iter->prev))
				continue ;
			delete_dup_node(token_list, &iter, &iter_next, &exp_flag);
		}
	}
	delete_empty_node(token_list);
}
