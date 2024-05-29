/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/29 10:10:21 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// avoid exiting with error code 1, unless error occurs
// we should lock the threads before creating them
void	philosphize(t_data_list *data, char **argv)
{
	int			i;

	i = 0;
	if (pthread_mutex_init(&data->fork, NULL) != 0)
		err_exit(6);
	struct_printer(data[0]);
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_create(&data[i].thread, NULL, &dinner_for_one, &data[i]) != 0)
			err_exit(7);
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_join(data[i].thread, NULL) != 0)
			err_exit(7);
		printf("HERE\n");//PRINTF
		i++;
	}
	pthread_mutex_destroy(&data->fork);
}

void	*dinner_for_one(void *data)
{
	t_data_list	*p_data;
	void		*butt = NULL;

	p_data = (t_data_list*)data;
	printf("Philosopher: %d: attempting to lock mutex\n", p_data->philo_id);
	pthread_mutex_lock(&p_data->fork);
	printf("Philosopher: %d: locked\n", p_data->philo_id);
	usleep(42);
	pthread_mutex_unlock(&p_data->fork);
	printf("Philosopher: %d: locked\n", p_data->philo_id);
	// struct_printer(*p_data);
	return (butt);
}
