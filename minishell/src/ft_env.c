/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:33:17 by phan              #+#    #+#             */
/*   Updated: 2023/08/10 11:38:52 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **simple_cmd, t_list **environ, int fd)
{
	t_list	*iter;

	g_error_status = 0;
	if (!simple_cmd)
		return ;
	iter = *environ;
	while (iter)
	{
		if (ft_strchr(iter->content, '='))
			ft_putendl_fd(iter->content, fd);
		iter = iter->next;
	}
}
