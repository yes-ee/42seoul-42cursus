/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:19:45 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/20 21:28:52 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_log(int id, t_info *info, char *msg, int die)
{
	long long	n;

	pthread_mutex_lock(&(info->m_print));
	n = get_time_ms();
	if (!info->end)
		printf("%llu %d %s\n", n - info->start_time, id + 1, msg);
	if (die)
		return ;
	pthread_mutex_unlock(&(info->m_print));
	return ;
}

void	philo_sleep(t_info *info, t_philo *philoi)
{
	long long	tsleep;

	tsleep = (long long)info->tsleep;
	print_log(philoi->num, info, "is sleeping", 0);
	philoi->last_sleep = get_time_ms();
	while (get_time_ms() - philoi->last_sleep < tsleep)
		usleep(100);
	return ;
}

void	philo_eat(t_info *info, t_philo *philoi)
{
	long long	time;

	pthread_mutex_lock(&(info->fork[philoi->left]));
	print_log(philoi->num, info, "has taken a fork", 0);
	if (info->nphilo != 1)
	{
		pthread_mutex_lock(&(info->fork[philoi->right]));
		philoi->last_eat = get_time_ms();
		print_log(philoi->num, info, "has taken a fork", 0);
		print_log(philoi->num, info, "is eating", 0);
		(philoi->eat_count)++;
		time = (long long)info->teat;
		while (get_time_ms() - philoi->last_eat < time)
			usleep(50);
		pthread_mutex_unlock(&(info->fork[philoi->right]));
	}
	else
		usleep((info->tdie + 1) * 1000);
	pthread_mutex_unlock(&(info->fork[philoi->left]));
}
