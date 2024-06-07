/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:01:07 by lstorey           #+#    #+#             */
/*   Updated: 2024/06/07 15:04:03 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > MAX_PHILOS ||
	ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 1 || ft_atoi(argv[4]) < 1)
	{
		ft_putstr_fd("Error: must be positive and above zero\n", 2);
		return (0);
	}
	else if (argv[5])
	{
		if (ft_atoi(argv[5]) < 0 || !ft_isdigit(argv[5][0]))
		{
			ft_putstr_fd("Error: must be positive and above zero\n", 2);
			return (0);
		}
	}
	return (1);
}

int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}
