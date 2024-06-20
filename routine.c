/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:56:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/20 11:36:06 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dying(t_data *data, t_overseer *overseer)
{
	if (overseer->sleep_time >= overseer->death_time) // need to add meals eaten
	{
		overseer->death_flag = 1;
		microphone(data, overseer, "has died");
		pthread_mutex_lock(data->right_fork);
		return (0);
	}
	return (1);
}

int	eating(t_data *data, t_overseer *overseer)
{
	
	if (overseer->death_flag == 1) //|| overseer->eaten_flag == 1
		return (0);
	pthread_mutex_lock(data->right_fork); // segfault originates from here
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
	ft_usleep(5);
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