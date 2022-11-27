/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:56:53 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/27 14:32:34 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	act_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	text;
	static int				count;

	(void)context;
	kill(info->si_pid, SIGUSR1);
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
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("server : no argument needed\n", 1);
		return (1);
	}
	ft_putstr_fd("pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	act.sa_sigaction = act_handler;
	act.sa_flags = SIGINFO;
	sigemptyset(&(act.sa_mask));
	while (1)
	{
		sigaction(SIGUSR2, &act, 0);
		sigaction(SIGUSR1, &act, 0);
		pause();
	}
	return (0);
}
