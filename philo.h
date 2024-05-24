/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:43:13 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/22 16:05:45 by lstorey          ###   ########.fr       */
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
}	t_data_list;

/*					philo.c							*/
void		struct_clearer(t_data_list *data);
void		struct_filler(t_data_list *data, char **argv);
void		philosphize(t_data_list *data);
int			ft_atoi(const char *str);

/*					error_printer.c					*/
void		err_exit(int i);
void		ft_putstr_fd(char *str, int fd);

/*					parsing.c						*/
void		parsing(char **argv);
int			ft_isdigit(int c);

#endif
