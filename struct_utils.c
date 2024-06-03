/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:46 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/03 10:34:04 by fdessoy-         ###   ########.fr       */
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
		memset((*data), 0, sizeof(t_data));
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
	while (i < ft_atoi(argv[1]))
	{
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
	overseer->no_of_philosophers = ft_atoi(argv[1]);
	overseer->death_time = ft_atoi(argv[2]);
	overseer->feed_time = ft_atoi(argv[3]);
	overseer->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		overseer->times_to_eat = ft_atoi(argv[5]);
	overseer->start_time = what_time_is_it();
}

void	struct_printer(t_data **data, t_overseer *overseer, char **argv)
{
	int i = 0;

	while (i < ft_atoi(argv[1]))
	{
		printf("Philosophers: %i\n", data[i]->no_of_philosophers);
		printf("death time : %i\n", data[i]->death_time);
		printf("feed time  : %i\n", data[i]->feed_time);
		printf("sleep time : %i\n", data[i]->sleep_time);
		printf("start time : %zu\n", data[i]->start_time);
		printf("ID         : %i\n\n", data[i]->philo_id);
		i++;
	}
	printf("\n ======= OVERSEER  ======= \n\n");
	printf("Philosophers: %i\n", overseer->no_of_philosophers);
	printf("death time : %i\n", overseer->death_time);
	printf("feed time  : %i\n", overseer->feed_time);
	printf("sleep time : %i\n", overseer->sleep_time);
	printf("start time : %zu\n", overseer->start_time);
	return ;
}
