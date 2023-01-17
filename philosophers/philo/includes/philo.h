/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:55:55 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/17 22:23:24 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_info
{
	int				nphilo;
	int				tdie;
	int				teat;
	int				tsleep;
	int				neat;
	pthread_mutex_t	*fork;
}	t_info;

typedef struct s_philo
{
	int	id;
	int	left;
	int	right;
	int	last_eat;
	int	eat_count;
}	t_philo;

/* main.c */

/* ft_atoi.c */
int	ft_atoi(const char *str);

/* print_error.c*/
int	print_error(char *msg);

/* init.c */
int	init(t_info *info, t_philo **philo);
int	init_mutex(t_info *info);
int	destroy_mutex_all(t_info *info, int n);
int	init_philo(t_info info, t_philo **philo);

#endif