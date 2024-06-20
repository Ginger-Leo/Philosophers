/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:20:07 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/20 10:42:17 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	microphone(t_data *data, t_overseer *overseer, char *action)
{
	int	timestamp;

	pthread_mutex_lock(overseer->mic_lock);
	timestamp = what_time_is_it() - overseer->start_time;	
	printf("%i %i %s \n", timestamp, data->philo_id, action);
	pthread_mutex_unlock(overseer->mic_lock);
	return (1);
}
