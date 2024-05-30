/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:46 by fdessoy-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/30 09:56:44 by fdessoy-         ###   ########.fr       */
=======
/*   Updated: 2024/05/30 14:07:36 by fdessoy-         ###   ########.fr       */
>>>>>>> Leo
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
		memset(overseer, 0, sizeof(t_overseer));
<<<<<<< HEAD
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
=======
		memset((*data), 0, sizeof(t_data));
>>>>>>> Leo
		i++;
	}
	data[i] = NULL;
}

// the parsing function is taking care of negatives
// the ifs are unnecessary
void	struct_filler(t_data **data, t_overseer *overseer, char **argv)
{
	int	i;

	i = 0;
	(void)overseer;
	while (i < ft_atoi(argv[1]))
	{
<<<<<<< HEAD
		// data[i] = malloc(sizeof(t_data));
=======
>>>>>>> Leo
		data[i]->no_of_philosophers = ft_atoi(argv[1]);
		data[i]->death_time = ft_atoi(argv[2]);
		data[i]->feed_time = ft_atoi(argv[3]);
		data[i]->sleep_time = ft_atoi(argv[4]);
		if (argv[5])
			data[i]->times_to_eat = ft_atoi(argv[5]);
		data[i]->start_time = what_time_is_it();
		data[i]->philo_id = i + 1;
		i++;
	}
<<<<<<< HEAD
	// data[i] = NULL;
=======
>>>>>>> Leo
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
