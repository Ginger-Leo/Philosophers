/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:56:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/18 13:02:32 by fdessoy-         ###   ########.fr       */
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
		if (microphone(data, overseer, "died") == 0)
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
	if (overseer->death_flag == 1) //|| overseer->eaten_flag == 1)
	{
		if (overseer->eaten_flag == 1)
			printf("the flag is eaten\n");
		return (printf("first return 0 right at the top\n"), 0);
	}
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
	printf("after microphone and is eating message\n");
	(*data)->start_time = what_time_is_it();
	printf("after what time is it\n");
	if (im_gonna_barf(overseer, (*data)->times_to_eat--) == 0)
		return (printf("returning 0 after im gonna barf\n"), 0);
	ft_usleep((*data)->feed_time);
	pthread_mutex_unlock(overseer->forks[overseer->philo_id - 1]);
	microphone(data, overseer, "fork dropped");
	if ((*data)->philo_id == overseer->no_of_philosophers)
	{
		pthread_mutex_unlock(overseer->forks[0]);
		microphone(data, overseer, "other fork dropped");
	}
	else
	{
		pthread_mutex_unlock(overseer->forks[(*data)->philo_id]);
		microphone(data, overseer, "other fork dropped");
	}
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


// int	eating(t_data **data, t_overseer *overseer)
// {
// 	if (overseer->death_flag == 1 || overseer->eaten_flag == 1)
// 		return (0);
// 	if (wait_in_line_sir(overseer->forks[overseer->philo_id - 1, LOCK))
// 	pthread_mutex_lock(overseer->forks[overseer->philo_id - 1]);
// 	if ((*data)->philo_id == overseer->no_of_philosophers)
// 	{
// 		pthread_mutex_lock(overseer->forks[0]);
// 		greasy_microphone(data, overseer, "has taken a fork");
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(overseer->forks[(*data)->philo_id]);
// 		greasy_microphone(data, overseer, "has taken a fork");
// 	}
// 	if (im_gonna_barf(overseer, (*data)->times_to_eat--) == 0)
// 		return (0);
// 	greasy_microphone(data, overseer, "has taken a fork");
// 	greasy_microphone(data, overseer, "is eating");
// 	ft_usleep((*data)->feed_time);
// 	(*data)->start_time = what_time_is_it();
// 	pthread_mutex_unlock(overseer->forks[overseer->philo_id - 1]);
// 	if ((*data)->philo_id == overseer->no_of_philosophers)
// 		pthread_mutex_unlock(overseer->forks[0]);
// 	else
// 		pthread_mutex_unlock(overseer->forks[(*data)->philo_id]);
// 	return (1);
// }