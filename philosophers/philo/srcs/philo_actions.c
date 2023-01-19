#include "../includes/philo.h"

void	print_log(t_philo *philoi, unsigned long long t, char *msg)
{
	if (philoi->info->end)
		return ;
	pthread_mutex_lock(&(philoi->info->m_print));
	printf("%llu %d %s\n", t, philoi->num, msg);
	pthread_mutex_unlock(&(philoi->info->m_print));
	return ;
}

void	philo_sleep(t_info *info, t_philo *philoi)
{
	unsigned long long	now;

	philoi->last_sleep = get_time_ms();
	now = philoi->last_sleep - info->start_time;
	print_log(philoi, now, "is sleeping");
	while (get_time_ms() - philoi->last_sleep < info->tsleep)
		usleep(100);
	return ;
}

void	philo_think(t_info *info, t_philo *philoi)
{
	unsigned long long	now;

	now = get_time_ms() - info->start_time;
	print_log(philoi, now, "is thinking");
	return ;
}

void	philo_eat(t_info *info, t_philo *philoi)
{
	unsigned long long	now;

	pthread_mutex_lock(&info->fork[philoi->left]);
	print_log(philoi, get_time_ms() - info->start_time, "has taken a fork");
	if (info->nphilo != 1)
	{
		pthread_mutex_lock(&info->fork[philoi->right]);
		philoi->last_eat = get_time_ms();
		now = philoi->last_eat - info->start_time;
		print_log(philoi, now, "has taken a fork");
		print_log(philoi, now, "is eating");
		while (get_time_ms() - philoi->last_eat < info->teat)
			usleep(100);
		philoi->eat_count++;
		pthread_mutex_unlock(&info->fork[philoi->right]);
	}
	pthread_mutex_unlock(&info->fork[philoi->left]);
	return (0);
}
