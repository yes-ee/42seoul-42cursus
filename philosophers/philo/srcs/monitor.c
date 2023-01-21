/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:04:56 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/22 03:07:21 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_end(t_info *info)
{
	pthread_mutex_lock(&(info->m_end));
	if (info->end == 1)
	{
		pthread_mutex_unlock(&(info->m_end));
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&(info->m_end));
		return (0);
	}
	return (0);
}

int	eat_cnt(t_info *info)
{
	int	cnt;

	pthread_mutex_lock(&(info->m_eat));
	cnt = info->eat_finish;
	pthread_mutex_unlock(&(info->m_eat));
	return (cnt);
}

int	check_dead(t_info *info, t_philo **philo)
{
	int			i;
	long long	last;

	i = -1;
	while (++i < info->nphilo)
	{
		pthread_mutex_lock(&((*philo)[i].p_time));
		last = (*philo)[i].last_eat;
		pthread_mutex_unlock(&((*philo)[i].p_time));
		if (get_time_ms() - last > (long long)info->tdie)
		{
			pthread_mutex_lock(&(info->m_end));
			info->end = 1;
			pthread_mutex_unlock(&(info->m_end));
			print_log(i, info, "died", 1);
			return (1);
		}
	}
	return (0);
}

void	monitor(t_info *info, t_philo **philo)
{
	while (!check_end(info))
	{
		if (eat_cnt(info) == info->nphilo)
		{
			pthread_mutex_lock(&(info->m_end));
			info->end = 1;
			pthread_mutex_unlock(&(info->m_end));
			break ;
		}
		if (check_dead(info, philo))
			break ;
	}
}
