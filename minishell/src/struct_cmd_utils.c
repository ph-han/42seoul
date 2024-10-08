/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:49:03 by phan              #+#    #+#             */
/*   Updated: 2023/08/11 17:00:00 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_type(t_token **type_list, t_token *node)
{
	char	*tmp;

	tmp = node->content;
	node->content = ft_strdup(node->next->content);
	free(tmp);
	ft_tokendel_mid(type_list, node->next);
}

char	**make_simple_cmd(t_token *word_list)
{
	t_token	*iter;
	char	**ret;
	int		size;

	iter = word_list;
	size = 0;
	while (iter)
	{
		size++;
		iter = iter->next;
	}
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		exit(1);
	iter = word_list;
	size = 0;
	while (iter)
	{
		ret[size++] = ft_strdup(iter->content);
		iter = iter->next;
	}
	ret[size] = NULL;
	return (ret);
}

void	insert_cmd_into_pipeline(t_cmd **cmd, \
	t_token **word_list, t_cmd **pipeline)
{
	(*cmd)->simple_cmd = make_simple_cmd(*word_list);
	ft_tokenclear(word_list, free);
	ft_cmdadd_back(pipeline, *cmd);
}

void	insert_word_into_list(t_token **list, int type, char *content)
{
	t_token	*new;

	new = ft_token_new(type, ft_strdup(content));
	ft_tokenadd_back(list, new);
}

void	handle_word_insertion(t_token *iter, t_token **word_list, \
	t_cmd **cmd, t_cmd **pipeline)
{
	if (iter->type == WORD)
		insert_word_into_list(word_list, WORD, iter->content);
	else if (iter->type == PIPE)
	{
		insert_cmd_into_pipeline(cmd, word_list, pipeline);
		*cmd = ft_cmd_new();
	}
}
