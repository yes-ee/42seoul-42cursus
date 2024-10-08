/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:44:23 by yeselee           #+#    #+#             */
/*   Updated: 2023/02/12 01:34:34 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	unlink_semaphore(void)
{
	sem_unlink("fork");
	sem_unlink("eat_finish");
	sem_unlink("end");
	return (1);
}

int	close_game(t_info *info)
{
	unlink_semaphore();
	free(info->pid);
	return (1);
}

int	print_error(char *msg)
{
	printf("Error : %s\n", msg);
	return (1);
}
