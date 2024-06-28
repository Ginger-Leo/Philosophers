/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:56:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/28 17:35:11 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dying(t_overseer *overseer, t_data *data)
{
	if (overseer->death_flag == 1)
		return (0);
	if ((what_time_is_it() - data->last_time_eaten >= overseer->death_time)
		&& overseer->can_i_print == 0)
	{
		if (pthread_mutex_lock(overseer->death_lock) != 0)
			return (0);
		overseer->death_flag = 1;
		microphone(data, overseer, "died");
		overseer->can_i_print = 1;
		if (pthread_mutex_unlock(overseer->death_lock) != 0)
			return (0);
		return (0);
	}
	if (overseer->death_flag == 1)
		return (0);
	return (1);
}	

int	eat_pray_love(t_data *data, t_overseer *overseer)
{
	if (overseer->death_flag == 1 || data->times_eaten >= overseer->times_to_eat)
		return (0);
	try_pick_fork(data, overseer);
	pthread_mutex_lock(overseer->meal_lock);
	data->last_time_eaten = what_time_is_it();
	pthread_mutex_unlock(overseer->meal_lock);
	if (microphone(data, overseer, "is eating") == 0)
		return (0);
	data->times_eaten += 1;
	ft_usleep(overseer->feed_time, overseer);
	pthread_mutex_unlock(data->left_fork);
	pthread_mutex_unlock(data->right_fork);
	if (microphone(data, overseer, "is sleeping") == 0)
		return (0);
	ft_usleep(overseer->sleep_time, overseer);
	if (microphone(data, overseer, "is thinking") == 0)
		return (0);
	return (1);
}

int	try_pick_fork(t_data *data, t_overseer *overseer)
{
	int i;

	while (1)
	{
		i = 0;
		if (!pthread_mutex_lock(data->right_fork))
		{
			i++;
			microphone(data, overseer, "has taken a r-fork");
		}
		if (!pthread_mutex_lock(data->left_fork))
			i++;
		if (i == 2)
		{
			microphone(data, overseer, "has taken a l-fork");
			return (1);
		}
		else
			ft_usleep(100, overseer);
	}
}
