/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:13:56 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/05/29 10:20:33 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data_list	**data;

	if (argc == 5)
	{
		data = malloc(sizeof(t_data_list) * (ft_atoi(argv[1]) + 1));
		parsing(argv);
		struct_clearer(&data);
		struct_filler(data, argv);
		philosphize(&data, argv);
		// free structs
		// 
	}
	else
		err_exit(2);
	return (0);
}
