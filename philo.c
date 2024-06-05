/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/06/05 11:18:54 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// avoid exiting with error code 1, unless error occurs
// we should lock the threads before creating them
void	philosophize(t_data **data, t_overseer *overseer)
{
	int			i;

	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		if (pthread_mutex_init(data[i]->forks[i], NULL) != 0)
			nuka_cola("Mutex init failed\n", data, overseer);
		if (pthread_create(&data[i]->thread, NULL, &dinner_for_x,
				&data[i]) != 0)
			nuka_cola("Thread creation failed\n", data, overseer);
		i++;
	}
	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		if (pthread_join(data[i]->thread, NULL) != 0)
			nuka_cola("Thread creation failed\n", data, overseer);
		i++;
	}
}

void	*dinner_for_x(void *data)
{
	t_data			**p_data;
	t_overseer		*o_data;
	int				i;

	i = 0;
	p_data = (t_data **)data;
	o_data = (*p_data)->overseer;
	wait_in_line_sir(p_data, o_data, LOCK); //forks are locked
	while (o_data->eaten_flag != 1 && o_data->death_flag != 1) // this condition is neccessary for the simulation to continue until death
	{
		wait_in_line_sir(p_data, o_data, UNLOCK); //forks are unlocked
		printf("In dinner_for_x\n");
		died_of_cringe(p_data, o_data);
	}
	return (data);
}

void	wait_in_line_sir(t_data **data, t_overseer *overseer, int flag)
{
	int	i;

	i = 0;
	while (i < overseer->no_of_philosophers)
	{

		if (flag == LOCK)
		{
			if (pthread_mutex_lock(data[i]->forks[i]) != 0)
				nuka_cola("Mutex lock failure\n", data, overseer);
			printf("here\n");
		}
		if (flag == UNLOCK)
		{
			if (pthread_mutex_unlock(data[i]->forks[i]) != 0)
				nuka_cola("Mutex unlock failure\n", data, overseer);
			usleep(42 * 1000);
		}
		i++;
	}
}

void	died_of_cringe(t_data **data, t_overseer *overseer)
{
	if ((*data)->sleep_time > (*data)->death_time)
	{
		overseer->death_flag = 1;
		nuka_cola("DED", data, overseer);
	}
}