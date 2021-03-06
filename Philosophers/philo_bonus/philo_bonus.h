/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:30 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/06 13:19:52 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

# define INT_MAX 2147483647
# define DIE 1
# define FULL 2

typedef struct s_philo
{
	pid_t				pid;
	int					id;
	sem_t				*sem_last_eat;
	long				last_eat;
	sem_t				*sem_cnt_eat;
	int					cnt_eat;
	struct s_monitor	*monitor;
}	t_philo;

typedef struct s_monitor
{
	int				num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_flag;
	int				must_eat;
	struct timeval	start_time;
	sem_t			*sem_start;
	int				finish_type;
	sem_t			*sem_finish;
	int				full_cnt;
	sem_t			*sem_full;
	sem_t			*sem_print;
	sem_t			*fork;
	t_philo			*philo;
}	t_monitor;

/* initialize.c */
void	init_sem(t_monitor *monitor);
int		init_philo(t_monitor *monitor, t_philo *philo, int i);
int		init_monitor(t_monitor *monitor, int argc, char *argv[]);

/* print_state.c */
int		print_take_fork_state(t_philo *philo);
int		print_eat_state(t_philo *philo);
int		print_sleep_state(t_philo *philo);
int		print_think_state(t_philo *philo);
int		print_finish_state(t_philo *philo);

/* philo_utils.c */
void	finish_with_error(char *message, t_monitor *monitor);
void	routine_takeoff_fork(t_philo *philo);
void	sleep_unit(t_monitor *monitor, long aim_time, \
					struct timeval start_time, long unit);
long	calc_timeval(struct timeval *start, struct timeval *end);
int		convert_arg_to_int(char *str);

/* routine */
void	routine(t_monitor *monitor, int id);

/* monitor */
int		monitor_main(t_monitor *monitor);
void	*monitor_philo(void *arg);

/* free_mem */
void	kill_process(t_monitor *monitor);
void	free_monitor(void);

int		print_error(char *message);

#endif