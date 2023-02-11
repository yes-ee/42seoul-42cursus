/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:34:58 by yeselee           #+#    #+#             */
/*   Updated: 2023/02/12 01:55:33 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
	if (info -> nphilo <= 0)
		return (1);
	if (info->tdie <= 0 || info->teat <= 0 || info->tsleep <= 0)
		return (1);
	return (0);
}

int	fork_philo(t_info *info)
{
	int	i;
	int	j;

	info->start_time = get_time_ms();
	if (info->start_time == 0)
		return (close_game(info));
	i = -1;
	while (++i < info->nphilo)
	{
		info->pid[i] = fork();
		if (info->pid[i] == 0)
			return (start_philo(info, i));
		else if (i < 0)
		{
			j = -1;
			while (++j < i)
				kill(info->pid[j], SIGTERM);
			return (close_game(info));
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (arg_check(&info, argc, argv))
		return (print_error("argument error"));
	if (init(&info))
		return (1);
	if (fork_philo(&info))
		return (print_error("fork philo error"));
	
	//부모 프로세스이면 -> 모니터링
	//자식 프로세스이면 -> 철학자 스레드 생성 && 자기 스레드 모니터링 돌리기
	// close_game(&info, &philo);
	return (0);
}
