/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:31:34 by yeselee           #+#    #+#             */
/*   Updated: 2023/02/12 02:31:40 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	print_log(int id, t_info *info, char *msg, int die)
{
	long long	n;

	pthread_mutex_lock(&(info->m_print));
	n = get_time_ms();
	if (!check_end(info))
		printf("%llu %d %s\n", n - info->start_time, id + 1, msg);
	else if (die)
		printf("%llu %d %s\n", n - info->start_time, id + 1, msg);
	pthread_mutex_unlock(&(info->m_print));
	return ;
}

void	philo_sleep(t_info *info, t_philo *philoi)
{
	long long	tsleep;

	if (check_end(info))
		return ;
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

	// pthread_mutex_lock(&(info->fork[philoi->left]));
	sem_wait(info->fork);
	print_log(philoi->num, info, "has taken a fork", 0);
	if (info->nphilo != 1)
	{
		sem_wait(info->fork);
		// pthread_mutex_lock(&(info->fork[philoi->right]));
		pthread_mutex_lock(&(philoi->p_time));
		philoi->last_eat = get_time_ms();
		pthread_mutex_unlock(&(philoi->p_time));
		print_log(philoi->num, info, "has taken a fork", 0);
		print_log(philoi->num, info, "is eating", 0);
		(philoi->eat_count)++;
		time = (long long)info->teat;
		while (get_time_ms() - philoi->last_eat < time)
			usleep(50);
		// pthread_mutex_unlock(&(info->fork[philoi->right]));
	}
	else
		usleep((info->tdie + 1) * 1000);
	// pthread_mutex_unlock(&(info->fork[philoi->left]));
}

void	*routine(void *arg)
{
	t_info	*info;
	t_philo	*philoi;

	philoi = arg;
	info = philoi->info;
	while (1)
	{
		philo_eat(info, philoi);
		if (philoi->eat_count == info->neat)
			sem_post(info->eat_finish);
		philo_sleep(info, philoi);
		print_log(philoi->num, info, "is thinking", 0);
	}
	return (0);
}

//자식 프로세스 전용
int	start_philo(t_info *info, int num)
{
	t_philo	philoi;	//자신의 철학자 정보 가지고 있음
	char	*tmp;

	philoi.num = num;
	philoi.info = info;
	philoi.time = get_sem_name(num);
	philoi.last_eat = info->start_time;
	pthread_create(&(philoi.thread), NULL, routine, &philoi);
	monitor(info, &philoi);
	return (0);
}
