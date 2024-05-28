/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:01:07 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/28 10:23:00 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_atoi(argv[1]) < 1)
				err_exit(6);
			else if (ft_atoi(argv[2]) < 1)
				err_exit(6);
			else if (ft_atoi(argv[3]) < 1)
				err_exit(6);
			else if (ft_atoi(argv[4]) < 1)
				err_exit(6);
			if (ft_isdigit(argv[i][j]) == 0)
				err_exit(6);
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}
