/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:43:13 by lstorey           #+#    #+#             */
/*   Updated: 2024/06/07 15:01:03 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# define MAX_PHILOS 200
# define LOCK 1
# define UNLOCK 2
# define ERR_TIME "Time collection failed"
# define ERR_LOCK "Mutex failure"
# define ERR_MIC "Output failure"

typedef pthread_mutex_t	t_mtx;

typedef struct s_overseer
{
	pthread_t			thread;
	int				no_of_philosophers;
	int				death_time;
	int				feed_time;
	int				sleep_time;
	int				times_to_eat;
	int				death_flag;
	int				eaten_flag;
	size_t				start_time;
	t_mtx				**forks;
	t_mtx				*meal_lock;
	t_mtx				*mic_lock;
}	t_overseer;

typedef struct s_data
{
	pthread_t			thread;
	int				no_of_philosophers;
	int				death_time;
	int				feed_time;
	int				sleep_time;
	int				times_to_eat;
	size_t				start_time;
	int				philo_id;
	t_overseer			*overseer;
	t_mtx				**forks;
}	t_data;

/*					philo.c							*/
void		philosophize(t_data **data, t_overseer *overseer);
int		init_locks(t_overseer *overseer);
void		*dinner_for_x(void *data);
int		wait_in_line_sir(t_mtx *lock, int flag);
int		at_deaths_door(t_data **data, t_overseer *overseer);

/*					error_printer.c					*/
void		ft_putstr_fd(char *str, int fd);

/*					parsing.c						*/
int		parsing(char **argv);
int		ft_isdigit(int c);

/*					utils.c							*/
int		ft_atoi(const char *str);
size_t		what_time_is_it(void);
void		nuka_cola(char *str, t_overseer *overseer);
void		free_struct(t_data **data, t_overseer *overseer);

/*					struct_utils.c					*/
int		struct_filler(t_data **data, t_overseer *overseer, char **argv);
int		struct_bzero(t_data **data, t_overseer *overseer, char **argv);
int		overseer_filler(t_overseer *overseer, char **argv);
void		struct_printer(t_data **data, t_overseer *overseer, char **argv);

#endif
