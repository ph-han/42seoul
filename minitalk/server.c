/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:43:26 by phan              #+#    #+#             */
/*   Updated: 2023/07/11 21:10:34 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		printf("sig1\n");
	}
	else if (sig == SIGUSR2)
	{
		printf("sig2\n");
	}
}

int	main(int ac, char *av[])
{
	pid_t				pid;
	// struct sigaction	sa;
	
	(void)av;
	if (ac != 1)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	pid = getpid();
	printf("pid: %d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1);
}
