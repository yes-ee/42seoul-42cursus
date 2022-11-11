/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:56:59 by yeselee           #+#    #+#             */
/*   Updated: 2022/10/02 13:08:43 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int pid, char *msg)
{
	
}

int	main(int argc, char **argv)
{
	int	pid_server;

	if (argc != 3)
	{
		ft_putstr_fd("client : argument check needed\n", 1);
		return (0);
	}
	pid_server = ft_atoi(argv[1]);
	if (pid_server < 101 || pid_server > 99999)
	{
		ft_putstr_fd("check pid\n", 1);
		return (0);
	}
	send_msg(pid_server, argv[2]);

	return (0);
}
