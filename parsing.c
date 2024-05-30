/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:01:07 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/30 14:02:01 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		err_exit(1);
	else if (ft_atoi(argv[2]) < 1)
		err_exit(3);
	else if (ft_atoi(argv[3]) < 1)
		err_exit(4);
	else if (ft_atoi(argv[4]) < 1)
		err_exit(5);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) < 0 || !ft_isdigit(argv[5][0]))
			err_exit(8);
	}
}

int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}
