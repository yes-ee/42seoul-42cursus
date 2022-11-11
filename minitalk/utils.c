/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:26:23 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/11 16:36:55 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
		write(fd, s++, 1);
}

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

static int	change_num_minus(int minus, int num)
{
	if (minus == -1)
		num *= -1;
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || str[i] == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	num = change_num_minus(minus, num);
	return (num);
}
