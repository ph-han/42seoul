/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequotenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:44:17 by phan              #+#    #+#             */
/*   Updated: 2023/08/11 17:00:45 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*modify_word(char *word, char *wd_flag, int wd_len)
{
	char	*res;
	int		i;
	int		j;
	int		res_len;

	i = 0;
	res_len = 0;
	while (i < wd_len)
	{
		if (wd_flag[i++] != 1)
			res_len++;
	}
	res = (char *)malloc(res_len + 1);
	if (!res)
		exit(1);
	i = 0;
	j = 0;
	while (i < wd_len && j < res_len)
	{
		if (wd_flag[i] == 0)
			res[j++] = word[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

void	process_quotes_and_flags(char *wd_flag, char word, int *q_flag)
{
	if (word && word == '\"')
	{
		if (*q_flag != '\'')
			*wd_flag = 1;
		set_q_flag(q_flag, '\"');
	}
	else if (word && word == '\'')
	{
		if (*q_flag != '\"')
			*wd_flag = 1;
		set_q_flag(q_flag, '\'');
	}
}

void	dequotenize(t_token **type_list)
{
	t_token	*iter;
	char	*word;
	int		q_flag;
	char	*wd_flag;
	int		i;

	iter = *type_list;
	while (iter)
	{
		word = iter->content;
		q_flag = 0;
		wd_flag = (char *)ft_calloc(1, ft_strlen(word) + 1);
		i = 0;
		while (word[i])
		{
			process_quotes_and_flags(&wd_flag[i], word[i], &q_flag);
			i++;
		}
		iter->content = modify_word(word, wd_flag, ft_strlen(word));
		free(word);
		free(wd_flag);
		iter = iter->next;
	}
}
