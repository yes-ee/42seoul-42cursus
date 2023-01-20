/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:31:57 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/20 21:29:55 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	destroy_mutex_all(t_info *info, int n)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(info->m_print));
	pthread_mutex_destroy(&(info->m_eat));
	while (i < n)
	{
		pthread_mutex_destroy(&(info->fork[i]));
		i++;
	}
	return (0);
}

int	close_game(t_info *info, t_philo **philo)
{
	destroy_mutex_all(info, info->nphilo);
	free_all(info, philo);
	return (1);
}