/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:29:45 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/12 18:54:25 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*p;

	i = 0;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	if (ft_strlen(s) < start)
		return (0);
	while (i < len)
	{
		if (s[i] == '\0')
		{
			p[i] = '\0';
			return (p);
		}
		p[i] = s[start + i];
		i++;
	}
	return (p);
}
