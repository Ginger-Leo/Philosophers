/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:15 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/24 13:39:11 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_exit(int i)
{
	if (i == 1)
		ft_putstr_fd("Incorrect number of philosophers\n", 2);
	else if (i == 2)
		ft_putstr_fd("Incorrect arguments\n4 arguments needed\n", 2);
	else if (i == 3)
		ft_putstr_fd("Incorrect death time - must be postive\n", 2);
	else if (i == 4)
		ft_putstr_fd("Incorrect feed time - must be postive\n", 2);
	else if (i == 5)
		ft_putstr_fd("Incorrect sleep time - must be postive\n", 2);
	else if (i == 6)
		ft_putstr_fd("Arguments must be numbers\n", 2);
	else if (i == 7)
		ft_putstr_fd("Incorrect times to eat - must be postive", 2);
	exit(1);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}
