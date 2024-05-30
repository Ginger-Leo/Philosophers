/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:46 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/05/30 09:30:31 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	struct_bzero(t_data **data, t_overseer *overseer, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		data[i] = malloc(sizeof(t_data));
		memset(overseer, 0, sizeof(t_overseer *));
		data[i]->no_of_philosophers = 0;
		data[i]->death_time = 0;
		data[i]->feed_time = 0;
		data[i]->sleep_time = 0;
		data[i]->times_to_eat = 0;
		data[i]->start_time = 0;
		data[i]->philo_id = 0;
		// overseer->death_time = 0;
		// overseer->feed_time = 0;
		// overseer->sleep_time = 0;
		// overseer->times_to_eat = 0;
		// overseer->no_of_philosophers = 0;
		// overseer->start_time = 0;
		// overseer->philo_id = 0;
		i++;
	}
	data[i] = NULL;
}

// the parsing function is taking care of negatives
// the ifs are unnecessary
void	struct_filler(t_data **data, t_overseer *overseer, char **argv)
{
	int	i;

	(void)overseer;
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		// data[i] = malloc(sizeof(t_data));
		data[i]->no_of_philosophers = ft_atoi(argv[1]);
		data[i]->death_time = ft_atoi(argv[2]);
		data[i]->feed_time = ft_atoi(argv[3]);
		data[i]->sleep_time = ft_atoi(argv[4]);
		// data[i]->times_to_eat = ft_atoi(argv[5]);
		data[i]->start_time = what_time_is_it();
		data[i]->philo_id = i + 1;
		// struct_printer(data[i]);
		i++;
	}
	// data[i] = NULL;
}

void	struct_printer(t_data *data)
{
	printf("Philosophers: %i\n", data->no_of_philosophers);
	// printf("death time : %i\n", data->death_time);
	// printf("feed time  : %i\n", data->feed_time);
	// printf("sleep time : %i\n", data->sleep_time);
	// printf("start time : %zu\n", data->start_time);
	printf("ID         : %i\n", data->philo_id);
	return ;
}
