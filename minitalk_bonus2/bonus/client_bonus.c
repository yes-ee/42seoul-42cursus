/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:56:59 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/27 14:34:13 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

int	g_check;

void	recv_sig(int signum)
{
	if (signum == SIGUSR1)
		g_check = 1;
}

void	send_msg(int pid, char *msg)
{
	int	count;
	int	c;

	while (*msg)
	{
		c = *msg;
		count = 0;
		while (count < 8)
		{
			if ((c & 1) == 1)
			{
				if (kill(pid, SIGUSR1) != 0)
					return ;
			}
			else if ((c & 1) == 0)
				if (kill(pid, SIGUSR2) != 0)
					return ;
			while (g_check == 0)
				pause();
			g_check = 0;
			c = c >> 1;
			count++;
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;

	signal(SIGUSR1, recv_sig);
	ft_putstr_fd("pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	if (argc != 3)
	{
		ft_putstr_fd("client : argument check needed\n", 1);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	if (pid_server < 101 || pid_server > 99999)
	{
		ft_putstr_fd("check pid\n", 1);
		return (1);
	}
	send_msg(pid_server, argv[2]);
	return (0);
}
