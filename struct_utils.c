/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:46 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/13 10:24:18 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	struct_bzero(t_data **data, t_overseer *overseer, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		data[i] = malloc(sizeof(t_data));
		if (!data[i])
			return (0);
		memset(overseer, 0, sizeof(t_overseer));
		memset((*data), 0, sizeof(t_data));
		i++;
	}
	data[i] = NULL;
	return (1);
}

int	struct_filler(t_data **data, t_overseer *overseer, char **argv)
{
	int	i;

	if (overseer_filler(overseer, argv) == 0)
		return (0);
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
		data[i]->overseer = overseer;
		data[i]->forks = overseer->forks;
		i++;
	}
	return (1);
}

int	overseer_filler(t_overseer *overseer, char **argv)
{
	int	i;
	
	i = 0;

	overseer->no_of_philosophers = ft_atoi(argv[1]);
	overseer->death_time = ft_atoi(argv[2]);
	overseer->feed_time = ft_atoi(argv[3]);
	overseer->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		overseer->times_to_eat = ft_atoi(argv[5]);
	overseer->forks = malloc((overseer->no_of_philosophers + 1) * sizeof(t_mtx *));
	overseer->meal_lock = malloc(sizeof(t_mtx *));
	overseer->mic_lock = malloc(sizeof(t_mtx *));
	if (!overseer->forks || !overseer->meal_lock || overseer->mic_lock)
		return (0);
	overseer->start_time = what_time_is_it();

	while (i < overseer->no_of_philosophers)
	{
		overseer->forks[i] = malloc(sizeof(t_mtx));
		if (!overseer->forks)
			return (0);
		i++;
	}
	return (1);
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
		printf("ID         : %i\n", data[i]->philo_id);
		// printf("Fork	   : %p\n\n", data[i]->right_fork);
		i++;
	}
	printf("\n ======= OVERSEER  ======= \n\n");
	printf("Philosophers: %i\n", overseer->no_of_philosophers);
	printf("death time : %i\n", overseer->death_time);
	printf("feed time  : %i\n", overseer->feed_time);
	printf("sleep time : %i\n", overseer->sleep_time);
	printf("start time : %zu\n", overseer->start_time);
	// printf("Fork	   : %p\n", overseer->forks);
	return ;
}
