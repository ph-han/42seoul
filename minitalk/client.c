/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:43:46 by phan              #+#    #+#             */
/*   Updated: 2023/07/15 14:49:01 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return ((int)(result));
}

static void	send_bits(int pid, char c)
{
	int		bit;

	bit = -1;
	while (++bit < 8)
	{
		if (c & 1 << bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(125);
	}
}

static void	send_msg(int pid, char *str)
{
	while (*str)
		send_bits(pid, *str++);
	send_bits(pid, *str);
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
	send_msg(pid, av[2]);
}
