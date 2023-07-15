/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:59:41 by phan              #+#    #+#             */
/*   Updated: 2023/07/15 14:38:46 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_check_bit;

int	ft_atoi(const char *str)
{
	long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return ((int)(result));
}

void	send_bits(int pid, char c)
{
	int	bit;

	bit = -1;
	while (++bit < 8)
	{
		g_check_bit = 0;
		if (c & 1 << bit)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		while (!g_check_bit)
			;
		usleep(100);
	}
}

void	send_msg(int pid, char *str)
{
	while (*str)
		send_bits(pid, *str++);
	send_bits(pid, *str);
}

void	handler(int sig)
{
	g_check_bit = 1;
	if (sig == SIGUSR1)
	{
		write(1, "message send ok\n", 16);
		exit(0);
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	if (ac != 3)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid < 100 || pid > 99999)
		return (0);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_msg(pid, av[2]);
}
