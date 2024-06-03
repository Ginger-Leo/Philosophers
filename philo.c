/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/06/03 15:55:43 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"
// avoid exiting with error code 1, unless error occurs
// we should lock the threads before creating them
void	philosophize(t_data **data, t_overseer *overseer, char **argv)
{
	int			i;

	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		overseer->forks[i] = malloc(sizeof(t_mtx));
		data[i]->forks = overseer->forks;
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
	t_data			**p_data;
	t_overseer		*o_data;
	void			*butt = NULL;
	int				i;

	i = 0;
	p_data = (t_data **)data;
	o_data = (*p_data)->overseer;
	printf("Overseer death flag: %d (should be zero)\n", o_data->death_flag);
	while (o_data->eaten_flag != 1 && o_data->death_flag != 1) // this condition is neccessary for the simulation to continue until death
	{
		printf("Philosopher: %d: attempting to lock mutex\n", p_data[i]->philo_id);
		if (pthread_mutex_lock(p_data[i]->forks[i]) != 0)
			err_exit(9);
		printf("Philosopher: %d: locked\n", p_data[i]->philo_id);
		usleep(42000);
		if (pthread_mutex_unlock(p_data[i]->forks[i]) != 0)
			err_exit(10);
		printf("Philosopher: %d: unlocked\n", p_data[i]->philo_id);
	}
	return (butt);
}
