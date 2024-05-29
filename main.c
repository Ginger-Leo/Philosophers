/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:56 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/05/29 13:03:23 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data		**data;
	t_overseer	*overseer;

	if (argc == 5)
	{
		data = malloc(sizeof(t_data) * (ft_atoi(argv[1]) + 1));
		overseer = malloc(sizeof(t_overseer));
		parsing(argv);
		struct_bzero(data, overseer, argv);
		printf("here\n");
		struct_filler(data, overseer, argv);
		philosophize(data, overseer, argv);
		// free structs
		// 
	}
	else
		err_exit(2);
	return (0);
}
