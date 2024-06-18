/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:57:28 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/18 15:21:50 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_locks(t_overseer *overseer)
{
	int	 i;
	
	i = 0;
	if (pthread_mutex_init(overseer->mic_lock, NULL) != 0)
		nuka_cola(ERR_MUTEX, overseer);
	if (pthread_mutex_init(overseer->meal_lock, NULL) != 0)
		nuka_cola(ERR_MUTEX, overseer);
	while (i < overseer->no_of_philosophers)
	{
		if (pthread_mutex_init(overseer->forks[i], NULL) != 0)
			nuka_cola(ERR_MUTEX, overseer);
		i++;
	}
	return (1);
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
