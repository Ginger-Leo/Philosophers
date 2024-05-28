/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/28 11:12:51 by lstorey          ###   ########.fr       */
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
	data->no_of_philosophers = 0;
	data->death_time = 0;
	data->feed_time = 0;
	data->sleep_time = 0;
	data->times_to_eat = 0;
	data->start_time = 0;
	data->philo_id = 0;
}

void	struct_filler(t_data_list *data, char **argv)
{
	int	i;

	i = 0;
	data = (t_data_list *)malloc(sizeof(t_data_list) * ft_atoi(argv[1]));
	while (i < ft_atoi(argv[1]))
	{
		data[i].no_of_philosophers = ft_atoi(argv[1]);
		if (data[i].no_of_philosophers > MAX_PHILOS ||
			data->no_of_philosophers < 0)
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
		data[i].philo_id = i + 1;
		struct_printer(data[i]);//remove later
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
	while (i < data->no_of_philosophers)
	{
		pthread_create(&data[i].thread, NULL, &dinner_for_one, &data[i]);
		// printf("%i\n", data->no_of_philosophers);
		i++;
	}
	i = 0;
	while (i < data->no_of_philosophers)
	{
		pthread_join(data[i].thread, NULL);
		i++;
	}
	exit(1);
}

void	*dinner_for_one(void *data)
{
	t_data_list	*p_data;
	void	*butt;

	p_data = (t_data_list*)data;
	struct_printer(*p_data);
	return (butt);
}
