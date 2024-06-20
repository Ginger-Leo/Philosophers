/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:43:13 by lstorey           #+#    #+#             */
/*   Updated: 2024/06/20 13:24:46 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* libraries */
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>


/* defines */
# define MAX_PHILOS 200
# define LOCK 1
# define UNLOCK 2
# define DATA 99
# define OVERSEER 66
# define BOTH 69
# define ERR_TIME "Time collection failed"
# define ERR_MUTEX "Mutex failure"
# define ERR_MIC "Output failure"

/* structs */
typedef pthread_mutex_t	t_mtx;
typedef struct s_data t_data;

typedef struct s_overseer
{
	pthread_t			o_thread;
	int					no_of_philosophers;
	int					death_time;
	int					feed_time;
	int					sleep_time;
	int					times_to_eat;
	int					death_flag;
	int					eaten_flag; // shoud this be in the philos not OS
	size_t				start_time;
	t_mtx				*meal_lock;
	t_mtx				*mic_lock;
}	t_overseer;

typedef struct s_data
{
	pthread_t			p_thread;
	int					times_eaten;
	size_t				start_time;
	int					philo_id;
	t_overseer			*overseer;
	t_mtx				*right_fork;
	t_mtx				*left_fork;
}	t_data;

/*					philo.c							*/
void		philosophize(t_data **data, t_overseer *overseer);
void		*dinner_for_x(void *data);


/*					printer.c						*/
void		ft_putstr_fd(char *str, int fd);
int			microphone(t_data *data, t_overseer *overseer, char *action);

/*					routine.c						*/
int			dying(t_data *data, t_overseer *overseer);
int			eating(t_data *data, t_overseer *overseer);
int			thinking(t_data *data, t_overseer *overseer);
int			sleeping(t_data *data, t_overseer *overseer);

/*					parsing.c						*/
int			parsing(char **argv);
int			ft_isdigit(int c);

/*					utils.c							*/
int			ft_atoi(const char *str);
size_t		what_time_is_it(void);
void		nuka_cola(char *str, t_overseer *overseer, t_data *data);
void		free_struct(t_data **data);
void		ft_usleep(size_t milisecs);

/*					struct_utils.c					*/
int			struct_filler(t_data **data, t_overseer *overseer, char **argv);
int			struct_init(t_data **data, t_overseer *overseer, char **argv);
int			fork_me(t_data **data, t_overseer *overseer);
int			overseer_filler(t_overseer *overseer, char **argv);
// void		struct_printer(t_data **data, t_overseer *overseer); // remove

/*					locks.c							*/
int			init_locks(t_overseer *overseer, t_data **data);

/*					routine_utils.c					 */
int			im_gonna_barf(t_overseer *overseer, int meal);
int			the_line(t_data **data, t_overseer *overseer);

#endif
