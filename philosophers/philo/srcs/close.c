/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:31:57 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/22 03:53:05 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	destroy_mutex_all(t_info *info, t_philo **philo, int n)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(info->m_print));
	pthread_mutex_destroy(&(info->m_eat));
	pthread_mutex_destroy(&(info->m_end));
	while (i < n)
	{
		pthread_mutex_destroy(&(info->fork[i]));
		pthread_mutex_destroy(&((*philo)[i].p_time));
		i++;
	}
	return (0);
}

int	close_game(t_info *info, t_philo **philo)
{
	destroy_mutex_all(info, philo, info->nphilo);
	free_all(info, philo);
	return (1);
}

int	free_all(t_info *info, t_philo **philo)
{
	free(info->fork);
	free(*philo);
	return (1);
}

int	print_error(char *msg)
{
	printf("Error : %s\n", msg);
	return (1);
}
