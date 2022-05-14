/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:29:45 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/14 22:16:00 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*p;

	i = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	if (ft_strlen(s) <= start)
	{
		p[0] = '\0';
		return (p);
	}
	while ((s[start + i] != '\0') && (i < len))
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
