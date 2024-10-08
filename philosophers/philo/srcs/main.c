/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:34:58 by yeselee           #+#    #+#             */
/*   Updated: 2023/01/22 03:52:47 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	arg_check(t_info *info, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	info->nphilo = ft_atoi(argv[1]);
	info->tdie = ft_atoi(argv[2]);
	info->teat = ft_atoi(argv[3]);
	info->tsleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->neat = ft_atoi(argv[5]);
		if (info->neat <= 0)
			return (1);
	}
	else
		info->neat = -1;
	info->end = 0;
	info->eat_finish = 0;
	if (info->nphilo > 8191 || info -> nphilo <= 0)
		return (1);
	if (info->tdie <= 0 || info->teat <= 0 || info->tsleep <= 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info			info;
	t_philo			*philo;

	if (arg_check(&info, argc, argv))
		return (print_error("argument error"));
	if (init(&info, &philo))
		return (1);
	if (start_philo(&info, &philo))
		return (print_error("start philo error"));
	close_game(&info, &philo);
	return (0);
}
