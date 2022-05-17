#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	unsigned int		id;
	unsigned int		*last_eat;
	unsigned int		die_flag; // 철학자가 죽으면 monitor에 flag 1 -> 다른 철학자도 자원을 반납시켜 종료할 수 있도록 함.
	struct s_monitor	*monitor;
} t_philo;

typedef struct s_monitor
{
	unsigned int	num_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	must_flag;
	unsigned int	must_eat;
	unsigned int	error_flag;	// 예기치 못한 에러 발생 시에도 종료될 수 있도록 하는 flag
	t_philo			*philo;
	pthread_mutex_t	*m_fork; // fork라는 공유자원을 보호하기 위한 mutex
	unsigned int	*fork;
	pthread_mutex_t m_print; // print message가 겹치지 않게 하기 위한 mutex
} t_monitor;

# endif