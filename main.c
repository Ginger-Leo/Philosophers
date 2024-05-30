/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:56 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/05/30 10:48:43 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		**data;
	t_overseer	*overseer;

	if (count_args(argc) == 0)
		err_exit(2);
	data = malloc(sizeof(t_data) * (ft_atoi(argv[1]) + 1));
	overseer = malloc(sizeof(t_overseer));
	parsing(argv);
	struct_bzero(data, overseer, argv);
	struct_filler(data, overseer, argv);
	(void)overseer;
	// philosophize(data, overseer, argv);
	// free structs
	free_array(data);
	free(overseer);
	return (0);
}
