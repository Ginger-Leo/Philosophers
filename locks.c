/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:57:28 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/06/20 10:52:25 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_locks(t_overseer *overseer, t_data **data)
{
	if (pthread_mutex_init(overseer->mic_lock, NULL) != 0)
		nuka_cola(ERR_MUTEX, overseer, *data);
	if (pthread_mutex_init(overseer->meal_lock, NULL) != 0)
		nuka_cola(ERR_MUTEX, overseer, *data);
	return (1);
}
