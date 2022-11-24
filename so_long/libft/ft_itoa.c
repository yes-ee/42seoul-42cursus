/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:36:47 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/12 22:58:11 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_c_len(int n)
{
	int	c_len;

	c_len = 0;
	if (n == -2147483648)
		c_len = 11;
	else if (n == 0)
		c_len = 1;
	else if (n < 0)
	{
		c_len++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		c_len++;
	}
	return (c_len);
}

char	*ft_itoa(int n)
{
	int			c_len;
	long long	num;
	char		*c_arr;

	num = n;
	c_len = ft_c_len(n);
	c_arr = malloc((c_len + 1) * sizeof(char));
	if (!c_arr)
		return (0);
	if (n < 0)
	{
		c_arr[0] = '-';
		num *= -1;
	}
	else if (n == 0)
		c_arr[0] = '0';
	c_arr[c_len--] = '\0';
	while (num > 0)
	{
		c_arr[c_len--] = num % 10 + '0';
		num = num / 10;
	}
	return (c_arr);
}
