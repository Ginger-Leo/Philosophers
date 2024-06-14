/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:25 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/14 14:09:29 by fdessoy-         ###   ########.fr       */
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
	if ((*p_data)->no_of_philosophers % 2 == 0)
		ft_usleep(42);
	if (wait_in_line_sir(o_data->forks[(*p_data)->philo_id - 1], UNLOCK) == 0)
		nuka_cola("Mutex unlock failure\n", o_data);
	while (dying(p_data, o_data) != 0)
	{
		if (eating(p_data, o_data) == 0)
			break ;
		if (sleeping(p_data, o_data) == 0)
			break ;
		if (thinking(p_data, o_data) == 0)
			break ;
	}
	nuka_cola(NULL, o_data);
	return (data);
}
