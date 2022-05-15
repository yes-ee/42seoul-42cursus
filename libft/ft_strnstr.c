/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:00:20 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/15 13:39:19 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	blen;
	size_t	llen;
	size_t	j;
	size_t	i;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	blen = ft_strlen(big);
	llen = ft_strlen(little);
	while (big[i] && (i < len))
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j < len))
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}
