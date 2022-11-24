/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:35:23 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/12 16:35:31 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		d = (unsigned char *)dest;
		s = (unsigned char *)src;
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d = (unsigned char *)dest + n - 1;
		s = (unsigned char *)src + n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
