/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:12:28 by yeselee           #+#    #+#             */
/*   Updated: 2022/07/17 19:39:17 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(char *format)
{
	
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	{
		if (format[i] == '%')
		{
			len += ft_format(ap, format);
		}
		else
			len += ft_printchar(format[i]);
		i++;
	}	
	va_end(ap);
	return (len);
}
