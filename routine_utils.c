/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:47:54 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/17 12:01:51 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	im_gonna_barf(t_data **data, t_overseer *overseer)
{
	if ((*data)->times_to_eat == 0)
	{
		overseer->eaten_flag == 1;
		return (0);
	}
	return (1);
}

int	the_line(t_data **data, t_overseer *overseer)
{
	
}