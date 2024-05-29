/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:43:13 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/29 13:04:05 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# define MAX_PHILOS 200
# define ERR_TIME "time collection failed"

typedef pthread_mutex_t	t_mtx;

typedef struct s_overseer_list
{
	pthread_t			thread;
	int					no_of_philosophers;
	int					death_time;
	int					feed_time;
	int					sleep_time;
	int					times_to_eat;
	size_t				start_time;
	t_mtx				**forks;
}	t_overseer;

typedef struct s_data_list
{
	pthread_t			thread;
	int					no_of_philosophers;
	int					death_time;
	int					feed_time;
	int					sleep_time;
	int					times_to_eat;
	size_t				start_time;
	int					philo_id;
	t_mtx				**forks;
}	t_data;
/*					philo.c							*/
void		philosophize(t_data **data, t_overseer *overseer, char **argv);
void		*dinner_for_one(void *data);

/*					error_printer.c					*/
void		err_exit(int i);
void		ft_putstr_fd(char *str, int fd);

/*					parsing.c						*/
void		parsing(char **argv);
int			ft_isdigit(int c);

/*					utils.c							*/
int			ft_atoi(const char *str);
size_t		what_time_is_it(void);

/*					struct_utils.c					*/
void		struct_filler(t_data **data, t_overseer *overseer, char **argv);
void		struct_bzero(t_data **data, t_overseer *overseer, char **argv);
void		struct_printer(t_data *data);

#endif
