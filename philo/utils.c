/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:41:42 by phan              #+#    #+#             */
/*   Updated: 2023/08/26 15:40:39 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pilho.h"

void	free_all(t_master *master)
{
	free(master->fork_arr);
	free(master->philo_arr);
	free(master->mutex_arr);
}

int	ft_atoi(const char *str)
{
	long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str != '\0')
		return (-1);
	return ((int)(result));
}

int	check_arg(t_arg arg)
{
	return (arg.must_eat <= 0 || arg.time_to_sleep <= 0 || \
		arg.must_eat <= 0 || arg.time_to_die <= 0);
}

int	setting_master(int ac, char **av, t_master *master)
{
	int	i;

	master->arg.num_of_philos = ft_atoi(av[1]);
	if (master->arg.num_of_philos < 1)
		return (1);
	master->arg.time_to_die = ft_atoi(av[2]);
	master->arg.time_to_eat = ft_atoi(av[3]);
	master->arg.time_to_sleep = ft_atoi(av[4]);
	if (ac > 5)
		master->arg.must_eat = ft_atoi(av[5]);
	else
		master->arg.must_eat = INT32_MAX;
	master->fork_arr = (int *)malloc(sizeof(int) \
		* master->arg.num_of_philos);
	master->philo_arr = (t_philo *)malloc(sizeof(t_philo) \
		* master->arg.num_of_philos);
	master->mutex_arr = (t_mutex *)malloc(sizeof(t_mutex) \
		* master->arg.num_of_philos);
	master->is_end = check_arg(master->arg);
	i = 0;
	while (i < master->arg.num_of_philos)
		pthread_mutex_init(&(master->mutex_arr[i++]), NULL);
	master->start_time = get_msec();
	pthread_mutex_init(&master->dead_mutex, NULL);
	return (0);
}
