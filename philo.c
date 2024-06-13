/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:25 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/13 12:15:31 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// NB: exit is not allowed
void	philosophize(t_data **data, t_overseer *overseer)
{
	int			i;

	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		if (pthread_create(&data[i]->thread, NULL, &dinner_for_x,
				&data[i]) != 0)
			nuka_cola("Thread creation failed\n", overseer);
		i++;
	}
	i = 0;
	while (i < overseer->no_of_philosophers)
	{
		if (pthread_join(data[i]->thread, NULL) != 0)
			nuka_cola("Thread creation failed\n", overseer);
		i++;
	}
}

void	*dinner_for_x(void *data)
{
	t_data			**p_data;
	t_overseer		*o_data;

	p_data = (t_data **)data;
	o_data = (*p_data)->overseer;
	if (wait_in_line_sir(o_data->forks[(*p_data)->philo_id - 1], UNLOCK) == 0)
		nuka_cola("Mutex unlock failure\n", o_data);
	while (o_data->eaten_flag != 1 && o_data->death_flag != 1)
	{
		// eating_routine(p_data, o_data);
		if (at_deaths_door(p_data, o_data) == 0)
			break ;
	}
	if (o_data->death_flag == 1 || o_data->death_flag == 1)
		nuka_cola(NULL, o_data);
	return (data);
}

// void	eating_routine(t_data **data, t_overseer *overseer)
// {
// 	return ;
// }
