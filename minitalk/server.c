/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:43:26 by phan              #+#    #+#             */
/*   Updated: 2023/07/15 16:03:01 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putpid(pid_t pid)
{
	if (pid == 0)
		return ;
	ft_putpid(pid / 10);
	write(1, &"0123456789"[pid % 10], 1);
}

static void	handler(int sig)
{
	static char	c;
	static int	bits;

	if (sig == SIGUSR1)
		c = c | 1 << bits;
	bits++;
	if (bits == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;

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
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		;
}
