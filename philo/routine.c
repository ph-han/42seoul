/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:01:27 by phan              #+#    #+#             */
/*   Updated: 2023/08/26 18:18:43 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pilho.h"

void	picking(t_master *master, t_philo *philo)
{
	pthread_mutex_lock(&master->mutex_arr[philo->near_fork[LEFT]]);
	print_msg(philo, "has taken a fork");
	if (is_over(master, philo) || master->arg.num_of_philos == 1)
	{
		philo->dead_id = philo->id;
		pthread_mutex_unlock(&master->mutex_arr[philo->near_fork[LEFT]]);
		return ;
	}
	pthread_mutex_lock(&master->mutex_arr[philo->near_fork[RIGHT]]);
	if (is_over(master, philo))
	{
		philo->dead_id = philo->id;
		pthread_mutex_unlock(&master->mutex_arr[philo->near_fork[RIGHT]]);
		pthread_mutex_unlock(&master->mutex_arr[philo->near_fork[LEFT]]);
		return ;
	}
	print_msg(philo, "has taken a fork");
}

void	eating(t_master *master, t_philo *philo)
{
	philo->last_eat_time = get_msec();
	philo->eat_cnt++;
	print_msg(philo, "is eating");
	ft_usleep(philo->master->arg.time_to_eat);
	pthread_mutex_unlock(&master->mutex_arr[philo->near_fork[RIGHT]]);
	pthread_mutex_unlock(&master->mutex_arr[philo->near_fork[LEFT]]);
}

void	sleeping(t_master *master, t_philo *philo)
{
	print_msg(philo, "is sleeping");
	ft_usleep(master->arg.time_to_sleep);
	if (is_over(master, philo))
	{
		philo->dead_id = philo->id;
		return ;
	}
}

void	thinking(t_master *master, t_philo *philo)
{
	print_msg(philo, "is thinking");
	if (is_over(master, philo))
	{
		philo->dead_id = philo->id;
		return ;
	}
}

void	*routine(void *pilho)
{
	t_philo	*philo;

	philo = (t_philo *)pilho;
	if (philo->id % 2 == 0)
		ft_usleep(philo->master->arg.time_to_sleep);
	while (1)
	{
		if (end_routine(philo))
			break ;
		picking(philo->master, philo);
		if (end_routine(philo))
			break ;
		eating(philo->master, philo);
		if (end_routine(philo))
			break ;
		sleeping(philo->master, philo);
		if (end_routine(philo))
			break ;
		thinking(philo->master, philo);
		if (end_routine(philo))
			break ;
	}
	return (NULL);
}
