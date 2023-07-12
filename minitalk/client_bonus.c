/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:59:41 by phan              #+#    #+#             */
/*   Updated: 2023/07/12 21:21:54 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>

int ft_atoi(const char *str)
{
	int sign;
	long result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return ((int)(sign * result));
}

void send_bits(int pid, char c)
{
	int bit;

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

void send_msg(int pid, char *str)
{
	while (*str)
		send_bits(pid, *str++);
	send_bits(pid, *str);
}

void	handler(int sig)
{
	printf("sig: %d\n", sig);
	if (sig == SIGUSR1)
		write(1, "msg send ok\n", 13);
	exit(0);
}

int main(int ac, char *av[])
{
	pid_t pid;

	if (ac != 3)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid < 0 || pid > 99998)
		return (0);
	printf("client: %d\n", getpid());
	//send_msg(pid, av[2]);
	signal(SIGUSR1, handler);
	send_msg(pid, av[2]);
	while (1);
}