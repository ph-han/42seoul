/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:33:54 by phan              #+#    #+#             */
/*   Updated: 2023/08/10 11:39:20 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	p_handler(int sig)
{
	if (sig != SIGINT)
	{
		return ;
	}
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_error_status = 1;
}

void	c_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		exit(1);
	}
	else if (sig == SIGTERM)
		exit(0);
}
