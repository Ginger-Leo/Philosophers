/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:32 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/05/30 10:47:55 by fdessoy-         ###   ########.fr       */
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

void	free_array(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
