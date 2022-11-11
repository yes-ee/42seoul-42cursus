/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:56:59 by yeselee           #+#    #+#             */
/*   Updated: 2022/10/10 18:04:22 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

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
				write(1, "1", 1);
				kill(pid, SIGUSR1);
			}
			else if ((c & 1) == 0)
			{
				write(1, "0", 1);
				kill(pid, SIGUSR2);
			}
			usleep(125);
			c = c >> 1;
			count++;
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;

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
