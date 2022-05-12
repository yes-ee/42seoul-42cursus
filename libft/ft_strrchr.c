/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:52:47 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/12 17:54:00 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	*l;
	int		check;

	temp = (char *)s;
	check = 0;
	if (ft_strncmp(s, "", 1) == 0)
		return (temp);
	while (*temp != '\0')
	{
		if (*temp == (unsigned char)c)
		{
			l = temp;
			check = 1;
		}
		temp++;
	}
	if (*temp == (unsigned char)c)
		return (temp);
	if (check == 1)
		return (l);
	return (0);
}
