/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:55:55 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/16 22:17:11 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>

typedef struct s_info
{
	int	nphilo;
	int	tdie;
	int	teat;
	int	tsleep;
	int	neat;
}	t_info;

typedef struct s_philo
{
	int	num;
	int	id;
	int	left;
	int	right;
	int	eat_count;
}	t_philo;

/* main.c */

/* ft_atoi.c */
int	ft_atoi(const char *str);

/* print_error.c*/
int	print_error(char *msg);

#endif