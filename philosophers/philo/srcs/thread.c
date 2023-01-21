/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:31:57 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/22 03:05:21 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_info	*info;
	t_philo	*philoi;

	philoi = arg;
	info = philoi->info;
	while (!check_end(info))
	{
		philo_eat(info, philoi);
		if (philoi->eat_count == info->neat)
		{
			pthread_mutex_lock(&(info->m_eat));
			(info->eat_finish)++;
			pthread_mutex_unlock(&(info->m_eat));
			break ;
		}
		philo_sleep(info, philoi);
		print_log(philoi->num, info, "is thinking", 0);
	}
	return (0);
}

int	create_thread(t_info *info, t_philo **philo, int i)
{
	while (i < info->nphilo)
	{
		if (pthread_create(&(*philo)[i].thread, NULL, routine, &((*philo)[i])))
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

	i = -1;
	info->start_time = get_time_ms();
	if (info->start_time == 0)
		return (close_game(info, philo));
	while (++i < info->nphilo)
		(*philo)[i].last_eat = info->start_time;
	if (create_thread(info, philo, 0) || create_thread(info, philo, 1))
		return (close_game(info, philo));
	monitor(info, philo);
	i = -1;
	while (++i < info->nphilo)
		pthread_join((*philo)[i].thread, NULL);
	return (0);
}
