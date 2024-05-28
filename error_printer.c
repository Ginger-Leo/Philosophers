/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:15 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/28 13:12:38 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_exit(int i)
{
	if (i == 1)
		ft_putstr_fd("Incorrect number of philosophers (1 - 200)\n", 2);
	else if (i == 2)
		ft_putstr_fd("Incorrect arguments\n4 arguments needed\n", 2);
	else if (i == 3)
		ft_putstr_fd("Incorrect death time - must be postive / ≠ 0\n", 2);
	else if (i == 4)
		ft_putstr_fd("Incorrect feed time - must be postive / ≠ 0\n", 2);
	else if (i == 5)
		ft_putstr_fd("Incorrect sleep time - must be postive / ≠ 0\n", 2);
	else if (i == 6)
		ft_putstr_fd("Mutex initialization failed\n", 2);
	else if (i == 7)
		ft_putstr_fd("Thread creation failed\n", 2);
	exit(1);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}
