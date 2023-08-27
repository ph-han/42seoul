/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pilho.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phan <phan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:12:38 by phan              #+#    #+#             */
/*   Updated: 2023/08/26 15:41:17 by phan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILHO_H
# define PILHO_H

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

# define LEFT 0
# define RIGHT 1

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_mutex;

typedef struct s_arg
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}	t_arg;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			last_eat_time;
	int				eat_cnt;
	int				dead_id;
	int				near_fork[2];
	struct s_master	*master;
}	t_philo;

typedef struct s_master
{
	t_philo	*philo_arr;
	t_mutex	*mutex_arr;
	int		*fork_arr;
	t_mutex	dead_mutex;
	t_arg	arg;
	long	start_time;
	int		all_eat;
	int		is_end;
}	t_master;

// monitor
void	*monitor(void *mst);

// routine.c
void	*routine(void *pilho);

// routine_utils & utils.c
int		ft_atoi(const char *str);
int		check_arg(t_arg arg);
void	ft_usleep(long ms);
long	get_msec(void);
void	free_all(t_master *master);
int		setting_master(int ac, char **av, t_master *master);
void	print_msg(t_philo *philo, char *msg);
int		end_routine(t_philo *philo);
int		is_over(t_master *master, t_philo *philo);

#endif