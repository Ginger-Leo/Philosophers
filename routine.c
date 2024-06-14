/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:56:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/14 10:52:41 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dying(t_data **data, t_overseer *overseer)
{
	int	i;

	i = 0;
	if ((*data)->sleep_time > (*data)->death_time)
	{
		overseer->death_flag = 1;
		if (wait_in_line_sir(overseer->forks[i], LOCK) == 0)
			nuka_cola(NULL, overseer);
		microphone(data, overseer, "has died");
		return (0);
	}
	return (1);
}

void	eating(t_data **data, t_overseer *overseer)
{
	pthread_mutex_lock((*data)->forks[(*data)->philo_id]);
	pthread_mutex_lock((*data)->forks[(*data)->philo_id + 1]);
	usleep((*data)->feed_time);
	microphone(data, overseer, "is eating");
}


