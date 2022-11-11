/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:56:53 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/11 16:36:40 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	get_sig(int signum)
{
	static char	text;
	static int	count;

	if (signum == SIGUSR1)
		text += 1 << count;
	count++;
	if (count == 8)
	{
		write(1, &text, 1);
		text = 0;
		count = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	signal(SIGUSR1, get_sig);
	signal(SIGUSR2, get_sig);
	if (argc != 1)
	{
		ft_putstr_fd("server : no argument needed\n", 1);
		return (1);
	}
	ft_putstr_fd("pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
