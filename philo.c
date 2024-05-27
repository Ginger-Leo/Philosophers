/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/27 12:28:58 by lstorey          ###   ########.fr       */
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
		// struct_printer(data);
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
	data->times_to_eat = 0;
	data->start_time = 0;
}

void	struct_filler(t_data_list *data, char **argv)
{
	int	i;

	i = 0;
	data = (t_data_list *)malloc(sizeof(t_data_list) * atoi(argv[1]));
	while (i < atoi(argv[1]))
	{
		data[i].philosophers = ft_atoi(argv[1]);
		if (data[i].philosophers > MAX_PHILOS || data->philosophers < 0) 
			err_exit(1);
		data[i].death_time = ft_atoi(argv[2]);
		if (data[i].death_time < 0)
			err_exit(3);
		data[i].feed_time = ft_atoi(argv[3]);
		if (data[i].feed_time < 0)
			err_exit(4);
		data[i].sleep_time = ft_atoi(argv[4]);
		if (data[i].sleep_time < 0)
			err_exit(5);
		data[i].start_time = what_time_is_it();
		struct_printer(data[i]);
		i++;
	// if (argv[5])
	// {
	// 	data->times_to_eat = ft_atoi(argv[5]);
	// 	if (data->times_to_eat < 0)
	// 		err_exit(7);
	// }
	}
	
}

void	philosphize(t_data_list *data)
{
	int			i;

	i = 0;
	while (i < data->philosophers)
	{
		pthread_create(&data[i].thread, NULL, &dinner_for_one, &data[i]);
		// printf("%i\n", data->philosophers);
		i++;
	}
	i = 0;
	while (i < data->philosophers)
	{
		pthread_join(data[i].thread, NULL);
		i++;
	}

	exit(1);
}

void	*dinner_for_one(void *data)
{
	t_data_list	*p_data;
	void *butt;

	p_data = (t_data_list*)data;
	struct_printer(*p_data);
	return (butt);
}
