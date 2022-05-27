#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define INT_MAX 2147483647
# define TAKE_FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

typedef struct s_philo
{
	int					id;
	struct timeval		last_eat;
	int					cnt_eat;
	int					error_flag;
	int					first_fork; // lowest number
	int					second_fork;
	struct s_monitor	*monitor;
} t_philo;

typedef struct s_monitor
{
	pthread_mutex_t	m_start;
	int				num_of_philo;
	long 			time_to_die;
	long 			time_to_eat;
	long			time_to_sleep;
	int				must_eat_flag;
	int				must_eat;
	struct timeval start_time;
	t_philo			*philo;
	pthread_mutex_t	*m_fork; // fork라는 공유자원을 보호하기 위한 mutex
	int				*fork;
	pthread_mutex_t m_print; // print message가 겹치지 않게 하기 위한 mutex
} t_monitor;

/* initialize.c */
int		init_monitor(t_monitor *monitor, int argc, char *argv[]);

/* philo_utils.c */
void	free_monitor(t_monitor *monitor);
long	calc_timeval(struct timeval *start, struct timeval *end);
int 	convert_arg_to_int(char *str);

/* routine */
void	*routine(void *arg);

# endif