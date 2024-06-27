/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:25 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/27 11:02:27 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophize(t_data **data, t_overseer *overseer)
{
	int			i;

	i = 0;
	overseer->start_time = what_time_is_it();
	while (i < overseer->no_of_philosophers)
	{
		data[i]->start_time = overseer->start_time;
		data[i]->last_time_eaten = overseer->start_time;
		if (pthread_create(&data[i]->p_thread, NULL, &dinner_for_x, data[i]) != 0)
			nuka_cola("Thread creation failed\n", overseer, data[i]);
		i++;
	}
	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		if (pthread_join(data[i]->p_thread, NULL) != 0)
			nuka_cola("Thread creation failed\n", overseer, data[i]);
		i++;
	}
}

void	*dinner_for_x(void *data)
{
	t_data			*p_data;

	p_data = (t_data *)data;
	if (p_data->philo_id % 2 == 0)
		ft_usleep(42);
	while (p_data->overseer->death_flag != 1 || p_data->times_eaten <= p_data->overseer->times_to_eat)
	{
		if (p_data->overseer->no_of_philosophers == 1)
		{
			dinner_for_one(p_data, p_data->overseer);
			break ;
		}
		if (dying(p_data, p_data->overseer) == 0)
			break ;
		if (eating(p_data, p_data->overseer) == 0)
			break ;
		if (sleeping(p_data, p_data->overseer) == 0)
			break ;
		if (thinking(p_data, p_data->overseer) == 0)
			break ;
	}
	nuka_cola(NULL, p_data->overseer, p_data);
	return (NULL);
}

void	dinner_for_one(t_data *data, t_overseer *overseer)
{
	ft_usleep(overseer->death_time);
	microphone(data, overseer, "has died");
}
