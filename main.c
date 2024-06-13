/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:56 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/13 10:26:01 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		**data;
	t_overseer	*overseer;

	if (argc == 5 || argc == 6)
	{
		data = malloc(sizeof(t_data) * (ft_atoi(argv[1]) + 1));
		if (!data)
			return (0);
		overseer = malloc(sizeof(t_overseer));
		if (!overseer)
			return (0);
		parsing(argv);
		if (struct_bzero(data, overseer, argv) == 0)
		{
			free_struct(data, overseer);
			return (0);
		}
		if (struct_filler(data, overseer, argv) == 0 ||
		init_locks(overseer) == 0)
		{
			free_struct(data, overseer);
			return (0);
		}
		philosophize(data, overseer);
		free_struct(data, overseer);
	}
	else
		ft_putstr_fd("Wrong number of arguments: must be five\n", 2);
	return (0);
}
