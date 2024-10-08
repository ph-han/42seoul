/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:18:20 by phan              #+#    #+#             */
/*   Updated: 2023/08/13 14:28:24 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(char **simple_cmd, t_list **environ, int fd)
{
	(void)fd;
	if (!environ)
		return ;
	if (simple_cmd[1] && ft_atouc(simple_cmd[1], \
		(unsigned char *)&g_error_status) == 0)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(simple_cmd[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		g_error_status = 255;
		exit(255);
	}
	else if (simple_cmd[1] && simple_cmd[2])
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(simple_cmd[1], 2);
		ft_putendl_fd(": too many arguments", 2);
		g_error_status = 1;
		return ;
	}
	exit(g_error_status);
}
