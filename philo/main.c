/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:12:32 by phan              #+#    #+#             */
/*   Updated: 2023/08/26 15:39:30 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pilho.h"

void	philo(t_master *master)
{
	int			i;
	pthread_t	monitor_trd;

	i = -1;
	while (++i < master->arg.num_of_philos)
	{
		master->philo_arr[i].id = (i + 1);
		master->philo_arr[i].last_eat_time = master->start_time;
		master->philo_arr[i].eat_cnt = 0;
		master->philo_arr[i].near_fork[LEFT] = i;
		master->philo_arr[i].near_fork[RIGHT] = \
			(i + 1) % master->arg.num_of_philos;
		master->philo_arr[i].dead_id = -1;
		master->philo_arr[i].master = master;
	}
	pthread_create(&monitor_trd, NULL, monitor, master);
	i = -1;
	while (++i < master->arg.num_of_philos)
		pthread_create(&master->philo_arr[i].thread, \
			NULL, routine, &master->philo_arr[i]);
	pthread_join(monitor_trd, NULL);
}

int	main(int ac, char **av)
{
	t_master	master;
	int			i;

	if (ac < 5 || ac > 6)
	{
		printf("Error: Check number of your arguments!");
		return (1);
	}
	if (setting_master(ac, av, &master))
		return (1);
	philo(&master);
	i = 0;
	while (i < master.arg.num_of_philos)
		pthread_join(master.philo_arr[i++].thread, NULL);
	i = 0;
	while (i < master.arg.num_of_philos)
		pthread_mutex_destroy(&master.mutex_arr[i++]);
	pthread_mutex_destroy(&master.dead_mutex);
	free_all(&master);
}
