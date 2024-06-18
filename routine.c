/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:56:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/18 13:30:57 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dying(t_data **data, t_overseer *overseer)
{
	int	i;

	i = 0;
	if ((*data)->sleep_time >= (*data)->death_time) // need to add meals eaten
	{
		overseer->death_flag = 1;
		if (microphone(data, overseer, "has died") == 0)
			return (0);
		while (i < overseer->no_of_philosophers)
		{
			if (wait_in_line_sir(overseer->forks[i], LOCK) == 0)
			{
				nuka_cola(NULL, overseer);
				return (0);
			}
			i++;
		}
		return (0);
	}
	return (1);
}

int	eating(t_data **data, t_overseer *overseer)
{
	if (overseer->death_flag == 1 || overseer->eaten_flag == 1)
		return (0);
	pthread_mutex_lock(overseer->forks[overseer->philo_id - 1]);
	microphone(data, overseer, "has taken a fork");
	if ((*data)->philo_id == overseer->no_of_philosophers)
	{
		pthread_mutex_lock(overseer->forks[0]);
		microphone(data, overseer, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(overseer->forks[(*data)->philo_id]);
		microphone(data, overseer, "has taken a fork");
	}
	microphone(data, overseer, "is eating");
	(*data)->start_time = what_time_is_it();
	// pthread_mutex_lock(overseer->meal_lock);
	// im_gonna_barf(overseer, (*data)->times_to_eat--);
	// pthread_mutex_unlock(overseer->meal_lock);
	ft_usleep((*data)->feed_time);
	pthread_mutex_unlock(overseer->forks[overseer->philo_id - 1]);
	if ((*data)->philo_id == overseer->no_of_philosophers)
		pthread_mutex_unlock(overseer->forks[0]);
	else
		pthread_mutex_unlock(overseer->forks[(*data)->philo_id]);
	return (1);
}

int	thinking(t_data **data, t_overseer *overseer)
{
	if (overseer->death_flag == 1 || overseer->eaten_flag == 1)
		return (0);
	if (microphone(data, overseer, "is thinking") == 0)
		return (0);
	return (1);	
}

int	sleeping(t_data **data, t_overseer *overseer)
{
	if (overseer->death_flag == 1 || overseer->eaten_flag == 1)
		return (0);
	if (microphone(data, overseer, "is sleeping") == 0)
		return (0);
	ft_usleep((*data)->sleep_time);
	return (1);
}
