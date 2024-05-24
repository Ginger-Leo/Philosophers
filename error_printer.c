/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:15 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/22 15:12:16 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_exit(int i)
{
	if (i == 1)
		ft_putstr_fd("Incorrect number of philosophers\n", 2);
	if (i == 2)
		ft_putstr_fd("Incorrect arguments\n4 arguments needed\n", 2);
	if (i == 3)
		ft_putstr_fd("Incorrect death time - must be postive\n", 2);
	if (i == 4)
		ft_putstr_fd("Incorrect feed time - must be postive\n", 2);
	if (i == 5)
		ft_putstr_fd("Incorrect sleep time - must be postive\n", 2);
	if (i == 6)
		ft_putstr_fd("Arguments must be numbers\n", 2);
	exit(1);
}

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}
