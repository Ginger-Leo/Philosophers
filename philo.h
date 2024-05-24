/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:43:13 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/24 14:14:12 by fdessoy-         ###   ########.fr       */
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

typedef struct s_data_list
{
	int					philosophers;
	int					death_time;
	int					feed_time;
	int					sleep_time;
	int					times_to_eat;
	size_t				start_time;
}	t_data_list;

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx		fork;
	int			fork_id;
}				t_fork;

/*					philo.c							*/
void		struct_clearer(t_data_list *data);
void		struct_filler(t_data_list *data, char **argv);
void		philosphize(t_data_list *data);
void		*dinner_for_one(void);

/*					error_printer.c					*/
void		err_exit(int i);
void		ft_putstr_fd(char *str, int fd);

/*					parsing.c						*/
void		parsing(char **argv);
int			ft_isdigit(int c);

/*					utils.c							*/
int			ft_atoi(const char *str);
size_t		what_time_is_it(void);

#endif
