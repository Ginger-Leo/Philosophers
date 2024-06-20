/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:56:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/20 09:34:42 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dying(t_data *data, t_overseer *overseer)
{
	int	i;

	i = 0;
	if (overseer->sleep_time >= overseer->death_time) // need to add meals eaten
	{
		overseer->death_flag = 1;
		if (microphone(data, overseer, "has died") == 0)
			return (0);
		while (i < overseer->no_of_philosophers)
		{
			if (wait_in_line_sir(data->right_fork, LOCK) == 0)
			{
				nuka_cola(NULL, overseer, data);
				return (0);
			}
			i++;
		}
		return (0);
	}
	return (1);
}

int	eating(t_data *data, t_overseer *overseer)
{
	
	if (overseer->death_flag == 1) //|| overseer->eaten_flag == 1
		return (0);
	pthread_mutex_lock(data->right_fork);
	microphone(data, overseer, "has taken a fork");
	pthread_mutex_lock(data->left_fork);
	microphone(data, overseer, "has taken a fork");
	microphone(data, overseer, "is eating");
	data->start_time = what_time_is_it();
	// pthread_mutex_lock(overseer->meal_lock);
	// im_gonna_barf(overseer, (*data)->times_to_eat--);
	// pthread_mutex_unlock(overseer->meal_lock);
	ft_usleep(overseer->feed_time);
	pthread_mutex_unlock(data->right_fork);
	pthread_mutex_unlock(data->left_fork);
	return (1);
}

int	thinking(t_data *data, t_overseer *overseer)
{
	if (overseer->death_flag == 1 || overseer->eaten_flag == 1)
		return (0);
	if (microphone(data, overseer, "is thinking") == 0)
		return (0);
	return (1);	
}

int	sleeping(t_data *data, t_overseer *overseer)
{
	if (overseer->death_flag == 1 || overseer->eaten_flag == 1)
		return (0);
	if (microphone(data, overseer, "is sleeping") == 0)
		return (0);
	ft_usleep(overseer->sleep_time);
	return (1);
}