/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:01:21 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/14 19:54:02 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		num = num * 10 + (*str- '0');
		str++;
	}
	num = change_num_minus(minus, num);
	return (num);
}
