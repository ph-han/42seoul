/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:58:30 by jonhan            #+#    #+#             */
/*   Updated: 2023/08/10 11:34:28 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**make_envp(t_list **env)
{
	t_list	*iter;
	char	**ret;
	int		size;

	iter = *env;
	size = 0;
	while (iter)
	{
		size++;
		iter = iter->next;
	}
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		exit(1);
	iter = *env;
	size = 0;
	while (iter)
	{
		ret[size++] = ft_strdup(iter->content);
		iter = iter->next;
	}
	ret[size] = NULL;
	return (ret);
}

t_list	*dup_envp(char **envp)
{
	t_list	*environ;
	int		i;

	environ = NULL;
	i = -1;
	while (envp[++i])
		ft_lstadd_back(&environ, ft_lstnew(ft_strdup(envp[i])));
	return (environ);
}
