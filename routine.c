/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:56:51 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/13 09:44:47 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	at_deaths_door(t_data **data, t_overseer *overseer)
{
	int	i;

	i = 0;
	if ((*data)->sleep_time > (*data)->death_time)
	{
		overseer->death_flag = 1;
		if (wait_in_line_sir(overseer->forks[i], LOCK) == 0)
			nuka_cola("Mutex lock failure\n", overseer);
		microphone("has died", overseer);
		return (0);
	}
	return (1);
}
