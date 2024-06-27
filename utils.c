/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:32 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/27 14:37:12 by fdessoy-         ###   ########.fr       */
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
	nuka_cola(NULL, overseer, data);
	while (i < overseer->no_of_philosophers)
	{
		// printf("THREAD GOT JOINED\n");
		if (pthread_join(data[i]->p_thread, NULL) != 0)
			nuka_cola("Thread join failed\n", overseer, data);
		i++;
	}
	i = 0;
	while (data[i])
	{
		free(data[i]->right_fork);
		free(data[i]);
		i++;
	}
	free(data);
	data = NULL;
	free(overseer->mic_lock);
	free(overseer);

}

void	nuka_cola(char *str, t_overseer *overseer, t_data **data)
{
	int	i;

	i = 0;
	if (str)
		ft_putstr_fd(str, 2);
	while (i < overseer->no_of_philosophers)
	{
		pthread_mutex_destroy(data[i]->right_fork);
		i++;
	}
	pthread_mutex_destroy(overseer->mic_lock);
}

void	ft_usleep(size_t milisecs, t_overseer *overseer)
{
	size_t	start;

	start = what_time_is_it();
	while ((what_time_is_it() - start) < milisecs)
	{
		if (overseer->death_flag == 1)
			return ;
		else
			usleep(500);
	}
}
