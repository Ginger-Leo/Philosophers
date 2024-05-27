/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:43:13 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/27 13:20:42 by lstorey          ###   ########.fr       */
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

typedef struct s_fork
{
	t_mtx		right_fork;
	int			r_fork_id;
	t_mtx		left_fork;
	int			l_fork_id;
}				t_fork;

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
	t_fork				forks;
}	t_data_list;

/*					philo.c							*/
void		struct_clearer(t_data_list *data);
void		struct_filler(t_data_list *data, char **argv);
void		philosphize(t_data_list *data);
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
void		struct_printer(t_data_list data);

#endif
