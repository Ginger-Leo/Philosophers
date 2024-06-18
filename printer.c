/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:20:07 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/17 10:39:24 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	microphone(t_data **data, t_overseer *overseer, char *action)
{
	int	timestamp;

	if (wait_in_line_sir(overseer->mic_lock, LOCK) == 0)
		return (0);
	timestamp = what_time_is_it() - overseer->start_time;	
	printf("%i %i %s \n", timestamp, (*data)->philo_id, action);
	if (wait_in_line_sir(overseer->mic_lock, UNLOCK) == 0)
		return (0);
	return (1);
}
