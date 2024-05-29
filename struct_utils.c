/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:46 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/05/29 10:19:46 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
// the parsing function is taking care of negatives
// the ifs are unnecessary
void	struct_filler(t_data_list **data, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		data[i] = malloc(sizeof(t_data_list));
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
	data[i] = NULL;
}

void	struct_printer(t_data_list data)
{
	printf("Philosophers: %i\n", data.no_of_philosophers);
	// printf("death time : %i\n", data.death_time);
	// printf("feed time  : %i\n", data.feed_time);
	// printf("sleep time : %i\n", data.sleep_time);
	// printf("start time : %zu\n", data.start_time);
	printf("ID         : %i\n", data.philo_id);
	return ;
}
