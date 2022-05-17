#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define INT_MAX 2147483647

typedef struct s_philo
{
	int	id;
	int	last_eat;
	int	cnt_eat;
	int	die_flag; // 철학자가 죽으면 monitor에 flag 1 -> 다른 철학자도 자원을 반납시켜 종료할 수 있도록 함.
	int	first_fork; // lowest number
	int	second_fork;
	struct s_monitor	*monitor;
} t_philo;

typedef struct s_monitor
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_flag;
	int	must_eat;
	int	finish_flag;
	t_philo			*philo;
	pthread_mutex_t	*m_fork; // fork라는 공유자원을 보호하기 위한 mutex
	int	*fork;
	pthread_mutex_t m_print; // print message가 겹치지 않게 하기 위한 mutex
} t_monitor;

/* initialize.c */
int	init_monitor(t_monitor *monitor, int argc, char *argv[]);


/* philo_utils.c */
int convert_arg_to_int(char *str);

# endif