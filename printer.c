/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:20:07 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/13 09:44:26 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	microphone(char *str, t_overseer *overseer)
{
	if (wait_in_line_sir(overseer->mic_lock, LOCK) == 0)
		return (0);
	printf("%s\n", str);
	if (wait_in_line_sir(overseer->mic_lock, UNLOCK) == 0)
		return (0);
	return (1);
}
