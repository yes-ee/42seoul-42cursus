/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:44:09 by yeselee           #+#    #+#             */
/*   Updated: 2023/02/12 02:39:31 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	init_semaphore(t_info *info)
{
	int	i;

	unlink_semaphore();
	info->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, info->nphilo);
	if (info->fork == SEM_FAILED)
		return (1);
	info->eat_finish = sem_open("eat_finish", O_CREAT | O_EXCL, 0644, 0);
	if (info->eat_finish == SEM_FAILED)
		return (unlink_semaphore());
	info->end = sem_open("eat_finish", O_CREAT | O_EXCL, 0644, 0);
	if (info->end == SEM_FAILED)
		return (unlink_semaphore());
	i = -1;
	while (i < info->nphilo)
	{
		
	}
	return (0);
}

int	init_pid(t_info *info)
{
	info->pid = malloc(sizeof(pid_t) * info->nphilo);
	if (!(info->pid))
		return (unlink_semaphore());
}

int	init(t_info *info)
{
	if (init_semaphore(info))
		return (print_error("init semaphore failed"));
	if (init_pid(info))
		return (print_error("init pid failed"));
	return (0);
}
