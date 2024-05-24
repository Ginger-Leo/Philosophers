/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:48:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/24 13:54:53 by fdessoy-         ###   ########.fr       */
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
	data->start_time = what_time_is_it();
	// if (argv[5])
	// {
	// 	data->times_to_eat = ft_atoi(argv[5]);
	// 	if (data->times_to_eat < 0)
	// 		err_exit(7);
	// }
}

void	philosphize(t_data_list *data)
{
	pthread_t p1;
	
	pthread_create(&p1, NULL, &dinner_for_one, NULL);
	pthread_join(p1, NULL);
	printf("%i\n", data->philosophers);
	exit(1);
}

void	*dinner_for_one(void)
{
	printf("this is philo1\n");
}
