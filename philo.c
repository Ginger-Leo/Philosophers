/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/06/07 14:57:12 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// NB: exit is not allowed
void	philosophize(t_data **data, t_overseer *overseer)
{
	int			i;

	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		if (pthread_create(&data[i]->thread, NULL, &dinner_for_x,
				&data[i]) != 0)
			nuka_cola("Thread creation failed\n", overseer);
		i++;
	}
	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		if (pthread_join(data[i]->thread, NULL) != 0)
			nuka_cola("Thread creation failed\n", overseer);
		i++;
	}
}

int		init_locks(t_overseer *overseer)
{
	int	 i;
	
	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		if (pthread_mutex_init(overseer->forks[i], NULL) != 0)
		{
			nuka_cola("Mutex init failed\n", overseer);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		if (wait_in_line_sir(overseer->forks[i], LOCK) == 0)
		{
			nuka_cola("Mutex lock failure\n", overseer);
			return (0);
		}
		i++;
	}
	return (1);
}

void	*dinner_for_x(void *data)
{
	t_data			**p_data;
	t_overseer		*o_data;

	p_data = (t_data **)data;
	o_data = (*p_data)->overseer;
	if (wait_in_line_sir(o_data->forks[(*p_data)->philo_id - 1], UNLOCK) == 0)
		nuka_cola("Mutex unlock failure\n", o_data);
	while (o_data->eaten_flag != 1 && o_data->death_flag != 1)
	{
		if (at_deaths_door(p_data, o_data) == 0)
			break ;
	}
	if (o_data->death_flag == 1 || o_data->death_flag == 1)
		nuka_cola(NULL, o_data);
	return (data);
}

int	wait_in_line_sir(t_mtx *lock, int flag)
{
	if (flag == LOCK)
	{
		if (pthread_mutex_lock(lock) != 0)
			return (0);
		return (1);
	}
	else if (flag == UNLOCK)
	{
		if (pthread_mutex_unlock(lock) != 0)
			return (0);		
		return (1);
	}
	return (0);
}

int	at_deaths_door(t_data **data, t_overseer *overseer)
{
	int	i;

	i = 0;
	if ((*data)->sleep_time > (*data)->death_time)
	{
		overseer->death_flag = 1;
		if (wait_in_line_sir(overseer->forks[i], LOCK) == 0)
			nuka_cola("Mutex lock failure\n", overseer);
		return (0);
	}
	return (1);
}

int	microphone(char *str, t_overseer *overseer)
{
	if (str)
	{
		if (wait_in_line_sir(overseer->mic_lock, LOCK) == 0)
			return (0);
		printf("%s\n", str);
		if (wait_in_line_sir(overseer->mic_lock, UNLOCK) == 0)
			return (0);
	}
	return (1);
}
