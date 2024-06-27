/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:56:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/27 11:02:22 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dying(t_data *data, t_overseer *overseer)
{
	size_t	current_time;
	size_t	elapsed_time;

	if (overseer->death_flag == 1)
		return (0);
	current_time = what_time_is_it();
	elapsed_time = current_time - data->last_time_eaten;
	if ((overseer->sleep_time >= overseer->death_time ||
	elapsed_time >= overseer->death_time) && overseer->can_i_print == 0)
	{
		overseer->death_flag = 1;
		microphone(data, overseer, "has died");
		overseer->can_i_print = 1;
		return (0);
	}
	return (1);
}

int	eating(t_data *data, t_overseer *overseer)
{
	if (overseer->death_flag == 1 || data->times_eaten >= overseer->times_to_eat) //|| overseer->eaten_flag == 1
		return (0);
	pthread_mutex_lock(data->right_fork);
	microphone(data, overseer, "has taken a fork");
	pthread_mutex_lock(data->left_fork);
	microphone(data, overseer, "has taken a fork");
	microphone(data, overseer, "is eating");
	data->times_eaten += 1;
	data->last_time_eaten = what_time_is_it();
	ft_usleep(overseer->feed_time);
	pthread_mutex_unlock(data->left_fork);
	pthread_mutex_unlock(data->right_fork);
	ft_usleep(5);
	return (1);
}

int	thinking(t_data *data, t_overseer *overseer)
{
	// printf("philo %i entered thinking\n", data->philo_id);
	if (overseer->death_flag == 1)
		return (0);
	if (microphone(data, overseer, "is thinking") == 0)
		return (0);
	return (1);	
}

int	sleeping(t_data *data, t_overseer *overseer)
{
	// printf("philo %i entered sleeping\n", data->philo_id);
	if (overseer->death_flag == 1)
		return (0);
	if (microphone(data, overseer, "is sleeping") == 0)
		return (0);
	ft_usleep(overseer->sleep_time);
	return (1);
}

// int	im_gonna_barf(t_overseer *overseer, int meal)
// {
// 	if (meal == overseer->times_to_eat)
// 	{
// 		overseer->eaten_flag = 1;
// 		return (0);
// 	}
// 	return (1);
// }