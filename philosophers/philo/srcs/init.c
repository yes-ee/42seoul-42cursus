/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:13:33 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/20 20:42:54 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philo(t_info *info, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * info->nphilo);
	if (!(*philo))
	{
		destroy_mutex_all(info, info->nphilo);
		return (1);
	}
	while (i < info->nphilo)
	{
		(*philo)[i].num = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->nphilo;
		(*philo)[i].eat_count = 0;
		(*philo)[i].info = info;
		(*philo)[i].last_eat = get_time_ms();
		i++;
	}
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(info->m_print), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(info->m_eat), NULL) != 0)
	{
		pthread_mutex_destroy(&(info->m_print));
		return (1);
	}
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nphilo);
	if (!(info->fork))
		return (1);
	while (i < info->nphilo)
	{
		if (pthread_mutex_init(&(info->fork[i]), NULL) != 0)
		{
			destroy_mutex_all(info, i);
			return (1);
		}
		i++;
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
