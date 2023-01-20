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
		return (1);
	while (i < info->nphilo)
	{
		(*philo)[i].num = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->nphilo;
		(*philo)[i].info = info;
		// (*philo)[i].last_eat = get_time_ms();
		i++;
	}
	return (0);
}

int	destroy_mutex_all(t_info *info, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&(info->fork[i]));
		i++;
	}
	return (0);
}

int	init_mutex(t_info *info, t_philo **philo)
{
	int	i;

	i = 0;
	info->fork = malloc(sizeof(pthread_mutex_t) * info->nphilo);
	if (!(info->fork))
		return (1);
	while (i < info->nphilo)
	{
		if (pthread_mutex_init(&(info->fork[i]), NULL) != 0)
		{
			destroy_mutex_all(info, i);
			free_all(info, philo);
			return (1);
		}
		i++;
	}
		// pthread_mutex_t m = (info->fork)[0];
		// printf("init ok\n");
	return (0);
}

int	init(t_info *info, t_philo **philo)
{
	if (init_philo(info, philo))
		return (print_error("init philo error"));
	if (init_mutex(info, philo))
		return (print_error("init mutex error"));
	printf("init success\n");

	// printf("thread 1 end %d\n", (*philo)[1].info->end);
	return (0);
}
