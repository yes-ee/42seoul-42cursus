/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:55:55 by yeselee           #+#    #+#             */
/*   Updated: 2023/02/12 02:40:50 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
// # include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

typedef struct s_info
{
	int				nphilo;
	int				tdie;
	int				teat;
	int				tsleep;
	int				neat;
	long long		start_time;
	pid_t			*pid;
	// int				end;
	// int				eat_finish;
	sem_t			*fork;
	sem_t			*eat_finish;
	sem_t			*end;
	sem_t			**p_time;
	// pthread_mutex_t	*fork;
	// pthread_mutex_t	m_print;
	// pthread_mutex_t	m_eat;
	// pthread_mutex_t	m_end;
}	t_info;

typedef struct s_philo
{
	int				num;
	// int				left;
	// int				right;
	long long		last_eat;
	long long		last_sleep;
	int				eat_count;
	t_info			*info;
	// sem_t			*time;
	// pthread_mutex_t	p_time;
	pthread_t		thread;
}	t_philo;

/* main.c */
int					arg_check(t_info *info, int argc, char **argv);

/* init.c */
int					init(t_info *info);
int					init_semaphore(t_info *info);
int					init_pid(t_info *info);
// int					init_philo(t_info *info, t_philo **philo);

/* utils.c */
int					ft_atoi(const char *str);
long long			get_time_ms(void);

/* thread.c */
// int					start_philo(t_info *info, t_philo **philo);
// int					create_thread(t_info *info, t_philo **philo, int i);

// /* monitor.c */
void				monitor(t_info *info, t_philo *philo);
// int					check_dead(t_info *info, t_philo **philo);
// int					check_end(t_info *info);
// int					eat_cnt(t_info *info);

// /* philo_actions.c */
// void				philo_eat(t_info *info, t_philo *philoi);
// void				philo_sleep(t_info *info, t_philo *philoi);
// void				print_log(int id, t_info *info, char *msg, int die);

/* close.c */
// int					destroy_mutex_all(t_info *info, t_philo **philo, int n);
int					close_game(t_info *info);
int					unlink_semaphore(void);
int					print_error(char *msg);
// int					free_all(t_info *info, t_philo **philo);

#endif