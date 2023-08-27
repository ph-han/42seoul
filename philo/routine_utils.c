/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:34:18 by phan              #+#    #+#             */
/*   Updated: 2023/08/27 15:40:45 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pilho.h"

int	end_routine(t_philo *philo)
{
	return (philo->master->is_end || philo->dead_id > -1);
}

int	is_over(t_master *master, t_philo *philo)
{
	return (get_msec() - philo->last_eat_time > master->arg.time_to_die);
}

void	print_msg(t_philo *philo, char *msg)
{
	long	time_diff;

	pthread_mutex_lock(&philo->master->dead_mutex);
	time_diff = get_msec() - philo->master->start_time;
	if (philo->dead_id == -1 && !philo->master->is_end)
		printf("%ld %d %s\n", time_diff, philo->id, msg);
	pthread_mutex_unlock(&philo->master->dead_mutex);
}

long	get_msec(void)
{
	t_time	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long ms)
{
	long	start;

	start = get_msec();
	while (get_msec() - start < ms)
		usleep(100);
}
