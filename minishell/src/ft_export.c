/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:48:11 by jonhan            #+#    #+#             */
/*   Updated: 2023/08/14 18:02:25 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(char **simple_cmd, t_list **environ, int fd)
{
	int		i;
	char	*word;
	t_list	*tmp;

	(void)fd;
	if (simple_cmd[1] == 0)
		print_export_list(environ, fd);
	i = 0;
	while (simple_cmd[++i])
	{
		word = make_word(simple_cmd[i]);
		if (!word)
			continue ;
		if (is_valid_export_arg(word, simple_cmd[i]))
		{
			tmp = ft_getenvnode(environ, word);
			if (tmp)
				ft_lstdel_mid(environ, tmp);
			ft_lstadd_back(environ, ft_lstnew(ft_strdup(simple_cmd[i])));
			g_error_status = 0;
		}
		else
			g_error_status = 1;
		free(word);
	}
}
