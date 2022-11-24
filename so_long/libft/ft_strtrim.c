/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:07:33 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/15 15:14:17 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		front;
	size_t		end;
	char		*p;

	front = 0;
	end = ft_strlen(s1);
	while (s1[front] != '\0' && ft_strchr(set, s1[front]))
		front++;
	while ((end != front) && (end - 1 != front) && ft_strchr(set, s1[end - 1]))
		end--;
	p = (char *)malloc(sizeof(char) * (end - front + 1));
	if (!p)
		return (0);
	ft_strlcpy(p, s1 + front, end - front + 1);
	return (p);
}
