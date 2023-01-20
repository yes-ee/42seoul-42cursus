/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:43:50 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/20 21:04:32 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	pass(const char **str)
{
	int	minus;

	minus = 1;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			minus = -1;
		(*str)++;
	}
	while (**str == '0')
		(*str)++;
	return (minus);
}

int	ft_atoi(const char *str)
{
	int			minus;
	int			len;
	long long	num;

	num = 0;
	len = 0;
	minus = pass(&str);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
		len++;
	}
	if (minus < 0 || len > 10 || num > 2147483647 || *str != '\0')
		return (0);
	return (num);
}

long long	get_time_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) < 0)
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	print_error(char *msg)
{
	printf("Error : %s\n", msg);
	return (1);
}

int	free_all(t_info *info, t_philo **philo)
{
	free(info->fork);
	free(*philo);
	return (1);
}
