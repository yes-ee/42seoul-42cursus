/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 22:56:25 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/15 14:01:43 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nb(int n, int fd)
{
	char	c;

	if (n > 0)
	{
		ft_nb(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	else if (n == 0)
		write(fd, "0", 1);
	if (n > 0)
		ft_nb(n, fd);
}
