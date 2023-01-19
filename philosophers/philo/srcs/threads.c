/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:31:57 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/19 16:25:17 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_info	*info;
	t_philo *philoi;

	philoi = arg;
	info = philoi->info;
	while (1)
	{
		philo_eat(info, philoi);
		if (philoi->eat_count == info->neat)
		{
			pthread_mutex_lock(&(info->m_end));
			info->end++;
			pthread_mutex_unlock(&(info->m_end));
			break;
		}
		philo_sleep(info, philoi);
		philo_think(info, philoi);
	}
	return ;
}

int	create_thread(t_info *info, t_philo **philo, int i)
{
	while (i < info->nphilo)
	{
		if (!pthread_create(&(philo[i]->thread), NULL, routine, &((*philo)[i])))
			return (1);
		i += 2;
	}
	if (i % 2 == 0)
		usleep(info->teat * 1000);
	return (0);
}

int	start_philo(t_info *info, t_philo **philo)
{
	int	i;

	i = 0;
	info->start_time = get_time_ms();
	if (info->start_time == 0)
		return (free_all(info, philo));
	if (create_thread(info, philo, 0) || create_thread(info, philo, 1))
		return (free_all(info, philo));
	
}
