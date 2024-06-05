/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/06/05 15:41:12 by fdessoy-         ###   ########.fr       */
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
		if (pthread_mutex_init(overseer->forks[i], NULL) != 0)
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
	while (o_data->forks[i])
	{
		if (wait_in_line_sir(o_data->forks[i], LOCK) == 0) //forks are locked
			nuka_cola("Mutex lock failure\n", p_data, o_data);
		if (wait_in_line_sir(o_data->forks[i], UNLOCK) == 0) //forks are unlocked
			nuka_cola("Mutex unlock failure\n", p_data, o_data);
		i++;
	}
	while (o_data->eaten_flag != 1 && o_data->death_flag != 1) // this condition is neccessary for the simulation to continue until death
	{
		died_of_cringe(p_data, o_data);
	}
	return (data);
}

int	wait_in_line_sir(t_mtx *fork, int flag)
{
	if (flag == LOCK)
	{
		if (pthread_mutex_lock(fork) != 0)
			return (0);
		usleep(42 * 1000);
		return (1);
	}
	if (flag == UNLOCK)
	{
		if (pthread_mutex_unlock(fork) != 0)
			return (0);		
		return (1);
	}
	return (0);
}

void	died_of_cringe(t_data **data, t_overseer *overseer)
{
	if ((*data)->sleep_time > (*data)->death_time)
	{
		overseer->death_flag = 1;
		nuka_cola("DED\n", data, overseer);
	}
}