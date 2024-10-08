/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:35:22 by phan              #+#    #+#             */
/*   Updated: 2023/08/09 16:49:18 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*struct_cmd(t_token **type_list)
{
	t_cmd	*pipeline;
	t_cmd	*cmd;
	t_token	*iter;
	t_token	*word_list;

	iter = *type_list;
	pipeline = NULL;
	word_list = NULL;
	cmd = ft_cmd_new();
	while (iter)
	{
		if (iter->type == WORD || iter->type == PIPE)
			handle_word_insertion(iter, &word_list, &cmd, &pipeline);
		else
		{
			redir_type(type_list, iter);
			insert_word_into_list(&(cmd->redir_header), \
				iter->type, iter->content);
		}
		if (iter->next == NULL)
			insert_cmd_into_pipeline(&cmd, &word_list, &pipeline);
		iter = iter->next;
	}
	return (pipeline);
}
