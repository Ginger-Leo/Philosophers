/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/22 15:56:26 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data_list	data;

	if (argc == 5)
	{
		parsing(argv);
		struct_clearer(&data);
		struct_filler(&data, argv);
		philosphize(&data);
	}
	else
		err_exit(2);
	return (0);
}

void	struct_clearer(t_data_list *data)
{
	data->philosophers = 0;
	data->death_time = 0;
	data->feed_time = 0;
	data->sleep_time = 0;
}

void	struct_filler(t_data_list *data, char **argv)
{
	data->philosophers = ft_atoi(argv[1]);
	if (data->philosophers > MAX_PHILOS || data->philosophers < 0) 
		err_exit(1);
	data->death_time = ft_atoi(argv[2]);
	if (data->death_time < 0)
		err_exit(3);
	data->feed_time = ft_atoi(argv[3]);
	if (data->feed_time < 0)
		err_exit(4);
	data->sleep_time = ft_atoi(argv[4]);
	if (data->sleep_time < 0)
		err_exit(5);
}

void	philosphize(t_data_list *data)
{
	printf("%i\n", data->philosophers);
	exit(1);
}

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
