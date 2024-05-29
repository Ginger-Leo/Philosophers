/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:56 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/05/29 11:47:54 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data_list		**data;
	t_overseer_list	*overseer;

	if (argc == 5)
	{
		data = malloc(sizeof(t_data_list) * (ft_atoi(argv[1]) + 1));
		overseer = malloc(sizeof(t_overseer_list));
		parsing(argv);
		struct_bzero(data, overseer, argv);
		struct_filler(data, overseer, argv);
		philosophize(data, overseer, argv);
		// free structs
		// 
	}
	else
		err_exit(2);
	return (0);
}
