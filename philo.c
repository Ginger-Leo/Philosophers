/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:25 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/20 11:44:41 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// NB: exit is not allowed
void	philosophize(t_data **data, t_overseer *overseer)
{
	int			i;

	i = 0;
	overseer->start_time = what_time_is_it();
	while (i < overseer->no_of_philosophers)
	{
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
	int				i;

	p_data = (t_data *)data;
	i = 0;
	if (p_data->philo_id % 2 == 0)
		ft_usleep(20);
	while (p_data->overseer->death_flag == 0) //|| o_data->eaten_flag != 1
	{
		if (eating(p_data, p_data->overseer) == 0)
			break ;
		if (sleeping(p_data, p_data->overseer) == 0)
			break ;
		if (thinking(p_data, p_data->overseer) == 0)
			break ;
		if (dying(p_data, p_data->overseer) == 0)
			break ;
		if (i == p_data->overseer->no_of_philosophers - 1)
			i = 0;
		else
			i++;
	}
	nuka_cola(NULL, p_data->overseer, p_data);
	return (data);
}
