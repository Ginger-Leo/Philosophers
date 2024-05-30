/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/30 09:30:30 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// avoid exiting with error code 1, unless error occurs
// we should lock the threads before creating them
void	philosophize(t_data **data, t_overseer *overseer, char **argv)
{
	int			i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_mutex_init(data[i]->forks[i], NULL) != 0)
			err_exit(6);
		if (pthread_create(&data[i]->thread, NULL, &dinner_for_one,
				&data[i]) != 0)
			err_exit(7); 
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_join(data[i]->thread, NULL) != 0)
			err_exit(7);
		printf("HERE\n");//PRINTF
		i++;
	}
	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		pthread_mutex_destroy(overseer->forks[i]);
		i++;
	}
}

void	*dinner_for_one(void *data)
{
	t_data	*p_data;
	void		*butt = NULL;

	p_data = (t_data*)data;
	// printf("Philosopher: %d: attempting to lock mutex\n", p_data->philo_id);
	// pthread_mutex_lock(&p_data->forks[i]);
	// printf("Philosopher: %d: locked\n", p_data->philo_id);
	// usleep(42);
	// pthread_mutex_unlock(&p_data->forks);
	// printf("Philosopher: %d: locked\n", p_data->philo_id);
	struct_printer((p_data));
	return (butt);
}
