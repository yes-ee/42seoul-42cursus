#include "../includes/philo_bonus.h"

int	init(t_info *info, t_philo **philo)
{
	info->fork = sem_open("sem", O_CREAT, 0644, info->nphilo);
	if (info->fork == SEM_FAILED)
		return (print_error("semaphore open error"));
	

	// if (init_mutex(info))
	// 	return (print_error("init mutex error"));
	// if (init_philo(info, philo))
	// 	return (print_error("init philo error"));
	return (0);
}
