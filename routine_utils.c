/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:47:54 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/20 13:17:13 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	im_gonna_barf(t_overseer *overseer, int meal)
{
	if (meal == overseer->times_to_eat)
	{
		overseer->eaten_flag = 1;
		return (0);
	}
	return (1);
}

// int	the_line(t_data **data, t_overseer *overseer)
// {
	
// }