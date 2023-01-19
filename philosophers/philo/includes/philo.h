/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:55:55 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/19 15:39:49 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>

# define U

typedef struct s_info
{
	int									nphilo;
	int									tdie;
	int									teat;
	int									tsleep;
	int									neat;
	unsigned long long	start_time;
	int									end;
	pthread_mutex_t			*fork;
	pthread_mutex_t			m_print;
	pthread_mutex_t			m_end;
} t_info;

typedef struct s_philo
{
	int			num;
	int			left;
	int			right;
	unsigned long long	last_eat;
	unsigned long long	last_sleep;
	int eat_count;
	t_info	*info;
	pthread_t thread;
}	t_philo;

/* main.c */

/* ft_utils.c */
int				ft_atoi(const char *str);
u_int64_t	get_time_ms(void);

/* print_error.c*/
int	print_error(char *msg);

/* init.c */
int	init(t_info *info, t_philo **philo);
int	init_mutex(t_info *info, t_philo **philo);
int	destroy_mutex_all(t_info *info, int n);
int	init_philo(t_info info, t_philo **philo);

int start_philo(t_info *info, t_philo **philo);

#endif