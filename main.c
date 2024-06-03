/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:56 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/03 10:31:49 by fdessoy-         ###   ########.fr       */
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
		overseer = malloc(sizeof(t_overseer));
		parsing(argv);
		data = malloc(sizeof(t_data) * (ft_atoi(argv[1]) + 1));
		overseer = malloc(sizeof(t_overseer));
		struct_bzero(data, overseer, argv);
		struct_filler(data, overseer, argv);
		struct_printer(data, overseer, argv);
		philosophize(data, overseer, argv);
		printf("we arrived safely here\n");
		// free structs
	}
	else
		err_exit(2);
	return (0);
}
