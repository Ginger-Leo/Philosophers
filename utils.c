/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:32 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/07 14:38:29 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long long	rtn;
	int			neg;
	int			i;

	rtn = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		rtn = (rtn * 10) + (str[i] - 48);
		i++;
	}
	return (rtn * neg);
}

size_t	what_time_is_it(void)
{
	struct timeval	time;

	if(gettimeofday(&time, NULL) == -1)
		ft_putstr_fd(ERR_TIME, 2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	free_struct(t_data **data, t_overseer *overseer)
{
	int	i;

	i = 0;
	while (overseer->forks[i])
	{
		free(overseer->forks[i]);
		i++;
	}
	free(overseer);
	free(overseer->forks);
	i = 0;
	if (data[i])
	{
		while (data[i])
		{
			free(data[i]);
			i++;
		}
		free(data);
	}
}

void	nuka_cola(char *str, t_overseer *overseer)
{
	int	i;

	i = 0;
	if (str)
		ft_putstr_fd(str, 2);
	while (i < overseer->no_of_philosophers)
	{
		// pthread_mutex_destroy(data[i]->forks[i]);
		pthread_mutex_destroy(overseer->forks[i]);
		i++;
	}
}
