/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:56:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/14 14:12:41 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dying(t_data **data, t_overseer *overseer)
{
	int	i;

	i = 0;
	if ((*data)->sleep_time >= (*data)->death_time)
	{
		overseer->death_flag = 1;
		if (wait_in_line_sir(overseer->forks[i], LOCK) == 0)
			nuka_cola(NULL, overseer);
		microphone(data, overseer, "has died");
		return (0);
	}
	return (1);
}

int	eating(t_data **data, t_overseer *overseer)
{
	if (dying(data, overseer) == 0)
		return (0);
	if (pthread_mutex_lock((*data)->forks[overseer->philo_id - 1]) != 0)
		return (0);
	if ((*data)->philo_id == MAX_PHILOS)
		if (pthread_mutex_lock((*data)->forks[0]) != 0)
			return (0);
	else
		pthread_mutex_lock((*data)->forks[(*data)->philo_id]);
	microphone(data, overseer, "is eating");
	ft_usleep((*data)->feed_time);
	if (pthread_mutex_unlock((*data)->forks[overseer->philo_id - 1]) != 0)
		return (0);
	pthread_mutex_unlock((*data)->forks[(*data)->philo_id]);
	return (1);
}

int	thinking(t_data **data, t_overseer *overseer)
{
	if (dying(data, overseer) == 0)
		return (0);
	microphone(data, overseer, "is thinking");
	return (1);	
}

int	sleeping(t_data **data, t_overseer *overseer)
{
	if (dying(data, overseer) == 0)
		return (0);
	microphone(data, overseer, "is sleeping");
	ft_usleep((*data)->sleep_time);
	return (1);
}
