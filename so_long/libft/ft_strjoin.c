/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:56:12 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/12 19:05:24 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*p;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!p)
		return (0);
	ft_memcpy(p, s1, len1);
	ft_memcpy(p + len1, s2, len2);
	p[len1 + len2] = '\0';
	return (p);
}
