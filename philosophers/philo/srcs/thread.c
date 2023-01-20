/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:31:57 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/20 21:29:55 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_end(t_info *info, t_philo **philo)
{
	int			i;
	long long	tdie;
	long long	now;

	tdie = (long long)info->tdie;
	while (info->end != 0)
	{
		i = 0;
		while (i < info->nphilo)
		{
			// usleep(100);
				// printf("if tdie %d %llu %llu %llu %llu\n", i, tdie, get_time_ms()-(*philo)[i].last_eat, get_time_ms(), (*philo)[1].last_eat);
			if (get_time_ms() - (*philo)[i].last_eat > tdie)
			{
				printf("ok\n\n\n\n");
				pthread_mutex_lock(&(info->m_end));
				now = get_time_ms() - info->start_time;
				info->end = 0;
				print_log(&((*philo)[i]), now, "died", 1);
				pthread_mutex_unlock(&(info->m_end));
				break;
			}
			i++;
		}
	}
	printf("end\n");
}

void	*routine(void *arg)
{
	t_info	*info;
	t_philo	*philoi;

	philoi = arg;
	info = philoi->info;
	// printf("thread info : %d %d %d %d\n", info->nphilo, info->tdie, info->teat, info->tsleep);
	// printf("philoi : num %d left %d right %d\n", philoi->num, philoi->left, philoi->right);
	while (info->end != 0)
	{
		printf("routine end %d\n", info->end);
		// printf("routine thread %d create end %d \n", philoi->num, info->end);
		philo_eat(info, philoi);
		// printf("thread %d philo eat end\n", philoi->num);
		// break;
		if (philoi->eat_count == info->neat)
		{
			pthread_mutex_lock(&(info->m_end));
			info->end--;
			pthread_mutex_unlock(&(info->m_end));
			break ;
		}
		philo_sleep(info, philoi);
		// printf("thread %d sleep end\n", philoi->num + 1);
		philo_think(info, philoi);
	}
	return (0);
}

int	create_thread(t_info *info, t_philo *philo, int i)
{
	printf("create thread i %d num %d \n", i, info->nphilo);
	while (i < info->nphilo)
	{
		if (pthread_create(&(philo[i].thread), NULL, routine, &(philo[i])))
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
		return (free_all(info, philo));
	while (++i < info->nphilo)
		(*philo)[i].last_eat = info->start_time;
	// printf("%llu\n", info->start_time);
	if (create_thread(info, *philo, 0) || create_thread(info, *philo, 1))
		return (free_all(info, philo));
	check_end(info, philo);
	i = 0;
	while (i < info->nphilo)
	{
		pthread_join(philo[i]->thread, NULL);
		i++;
	}
	return (0);
}
