/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:55:55 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/20 21:05:23 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>
# include <unistd.h>

# define U

typedef struct s_info
{
	int				nphilo;
	int				tdie;
	int				teat;
	int				tsleep;
	int				neat;
	long long		start_time;
	int				end;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_end;
}	t_info;

typedef struct s_philo
{
	int				num;
	int				left;
	int				right;
	long long		last_eat;
	long long		last_sleep;
	int				eat_count;
	t_info			*info;
	pthread_t		thread;
}	t_philo;

/* main.c */
int					arg_check(t_info *info, int argc, char **argv);

/* init.c */
int					init(t_info *info, t_philo **philo);
int					destroy_mutex_all(t_info *info, int n);
int					init_mutex(t_info *info, t_philo **philo);
int					init_philo(t_info *info, t_philo **philo);

/* utils.c */
int					ft_atoi(const char *str);
long long			get_time_ms(void);
int					print_error(char *msg);
int					free_all(t_info *info, t_philo **philo);

/* thread.c */
int					start_philo(t_info *info, t_philo **philo);
int					create_thread(t_info *info, t_philo *philo, int i);
void				check_end(t_info *info, t_philo **philo);

/* philo_actions.c */
void				philo_eat(t_info *info, t_philo *philoi);
void				philo_think(t_info *info, t_philo *philoi);
void				philo_sleep(t_info *info, t_philo *philoi);
void				print_log(t_philo *philoi, long long t, char *msg, int die);

#endif