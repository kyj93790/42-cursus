#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define INT_MAX 2147483647
# define DIE 0
# define FULL 1

typedef struct s_philo
{
	int					id;
	pthread_mutex_t		m_last_eat;
	long				last_eat;
	pthread_mutex_t		m_cnt_eat;
	int					cnt_eat;
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
	pthread_mutex_t	m_finish;
	int				finish_flag;
	struct timeval	start_time;
	pthread_t		*thread; // 나중에 init
	t_philo			*philo;
	pthread_mutex_t	*m_fork; // fork라는 공유자원을 보호하기 위한 mutex
	int				*fork;
	pthread_mutex_t m_print; // print message가 겹치지 않게 하기 위한 mutex
} t_monitor;

/* initialize.c */
int		init_monitor(t_monitor *monitor, int argc, char *argv[]);

/* print_state.c */
int	print_take_fork_state(t_philo *philo);
int	print_eat_state(t_philo *philo);
int	print_sleep_state(t_philo *philo);
int	print_think_state(t_philo *philo);
int	print_finish_state(t_philo *philo, int status);

/* philo_utils.c */
void	sleep_unit(t_monitor *monitor, long aim_time, struct timeval start_time, long unit);
void	free_monitor(t_monitor *monitor);
long	calc_timeval(struct timeval *start, struct timeval *end);
int 	convert_arg_to_int(char *str);

/* routine */
void	*routine(void *arg);

/* routine_one */
void	*routine_one(void *arg);

/* monitor */
int	monitor_philo(t_monitor *monitor);


int free_philo(t_monitor *monitor, int philo_num);
void free_fork(t_monitor *monitor, int philo_num);

int	print_error(char *message);

# endif