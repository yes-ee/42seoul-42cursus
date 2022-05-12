/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:00:20 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/12 16:08:05 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	blen;
	size_t	llen;
	size_t	n;

	if (*little == '\0')
		return ((char *)big);
	blen = ft_strlen(big);
	llen = ft_strlen(little);
	if (blen < llen || len < llen)
		return (0);
	if (blen > len)
		n = len;
	else
		n = blen;
	while (n >= llen)
	{
		if (ft_memcmp(big, little, llen) == 0)
			return ((char *)big);
		big++;
		n--;
	}
	return (0);
}
