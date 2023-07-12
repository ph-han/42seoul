/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:59:44 by phan              #+#    #+#             */
/*   Updated: 2023/07/12 20:47:52 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void ft_putpid(pid_t pid)
{
	if (pid == 0)
		return;
	ft_putpid(pid / 10);
	write(1, &"0123456789"[pid % 10], 1);
}
#include <stdio.h>
void handler(int sig, siginfo_t *info, void *tmp)
{
	static char c;
	static int bits;

	(void)tmp;
	if (sig == SIGUSR1)
		c = c | 1 << bits;
	bits++;
	if (bits == 8)
	{
		if (c == 0)
		{
			write(1, "\n", 1);
			printf("client pid : %d\n", info->si_pid);
			kill(info->si_pid, SIGUSR1);
		}
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int main(int ac, char *av[])
{
	pid_t				pid;
	struct sigaction	action;

	(void)av;
	if (ac != 1)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	pid = getpid();
	write(1, "pid : ", 6);
	ft_putpid(pid);
	write(1, "\n", 1);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1);
}
