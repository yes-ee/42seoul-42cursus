/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:13:33 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/17 22:30:40 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philo(t_info info, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * info.nphilo);
	if (!(*philo))
		return (1);
	while (i < info.nphilo)
	{
		(*philo)[i].num = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info.nphilo;
		(*philo)[i].info = &info;
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
			free(philo);
			free(info->fork);
			return (1);
		}
		i++;
	}
	return (0);
}

int	init(t_info *info, t_philo **philo)
{
	if (init_philo(*info, philo))
		return (print_error("init philo error"));
	if (init_mutex(info, philo))
		return (print_error("init mutex error"));
	return (0);
}
