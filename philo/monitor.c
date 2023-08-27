/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:14:55 by phan              #+#    #+#             */
/*   Updated: 2023/08/27 11:52:11 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pilho.h"

static void	end_meal(t_master *master)
{
	pthread_mutex_lock(&master->dead_mutex);
	if (master->all_eat == master->arg.num_of_philos)
		master->is_end = 1;
	pthread_mutex_unlock(&master->dead_mutex);
}

static void	end_die(t_master *master, int i)
{
	pthread_mutex_lock(&master->dead_mutex);
	printf("%ld %d died\n", \
		get_msec() - master->start_time, master->philo_arr[i].id);
	master->is_end = 1;
	pthread_mutex_unlock(&master->dead_mutex);
}

void	*monitor(void *mst)
{
	t_master	*master;
	int			i;

	master = (t_master *)mst;
	while (!master->is_end)
	{
		i = 0;
		master->all_eat = 0;
		while (i < master->arg.num_of_philos)
		{
			if (master->arg.must_eat > 0 && \
				master->philo_arr[i].eat_cnt >= master->arg.must_eat)
				master->all_eat++;
			if (is_over(master, &master->philo_arr[i]) || \
				master->philo_arr[i].dead_id == master->philo_arr[i].id)
			{
				end_die(master, i);
				break ;
			}
			i++;
		}
		end_meal(master);
	}
	return (NULL);
}
