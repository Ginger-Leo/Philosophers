/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/29 09:44:52 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// avoid exiting with error code 1, unless error occurs
// we should lock the threads before creating them
void	philosphize(t_data_list *data)
{
	int			i;

	if (pthread_mutex_init(&data->mutex, NULL) != 0)
		err_exit(6);
	i = 0;
	printf("No_of_philos: %i\n", data->no_of_philosophers);
	while (i < data->no_of_philosophers)
	{
		if (pthread_create(&data[i].thread, NULL, &dinner_for_one, &data[i]) != 0)
			err_exit(7);
		i++;
	}
	i = 0;
	while (i < data->no_of_philosophers)
	{
		if (pthread_join(data[i].thread, NULL) != 0)
			err_exit(7);
		i++;
	}
	pthread_mutex_destroy(&data->mutex);
}

void	*dinner_for_one(void *data)
{
	t_data_list	*p_data;
	void	*butt;
	
	p_data = (t_data_list*)data;
	
	printf("Philosopher: %d: attempting to lock mutex\n", p_data->philo_id);
	pthread_mutex_lock(&p_data->mutex);
	printf("Philosopher: %d: locked\n", p_data->philo_id);
	usleep(1);
	pthread_mutex_unlock(&p_data->mutex);
	printf("Philosopher: %d: locked\n", p_data->philo_id);
	// struct_printer(*p_data);
	return (butt);
}
