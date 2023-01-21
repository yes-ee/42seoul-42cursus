/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:13:33 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/22 03:19:33 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philo(t_info *info, t_philo **philo)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * info->nphilo);
	if (!(*philo))
		return (1);
	while (++i < info->nphilo)
	{
		(*philo)[i].num = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->nphilo;
		(*philo)[i].last_eat = get_time_ms();
		(*philo)[i].eat_count = 0;
		(*philo)[i].info = info;
	}
	i = -1;
	while (++i < info->nphilo)
	{
		if (pthread_mutex_init(&(*philo)[i].p_time, NULL) != 0)
			return (1);
	}
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&(info->m_print), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(info->m_eat), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(info->m_end), NULL) != 0)
		return (1);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nphilo);
	if (!(info->fork))
		return (1);
	i = -1;
	while (++i < info->nphilo)
	{
		if (pthread_mutex_init(&(info->fork[i]), NULL) != 0)
			return (1);
	}
	return (0);
}

int	init(t_info *info, t_philo **philo)
{
	if (init_mutex(info))
		return (print_error("init mutex error"));
	if (init_philo(info, philo))
		return (print_error("init philo error"));
	return (0);
}
