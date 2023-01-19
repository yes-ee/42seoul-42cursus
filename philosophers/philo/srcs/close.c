/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:11:19 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/16 22:12:42 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_error(char *msg)
{
	printf("Error : %s\n", msg);
	return (1);
}

int	free_all(t_info *info, t_philo **philo)
{
	free(info);
	free(philo);
	return (1);
}