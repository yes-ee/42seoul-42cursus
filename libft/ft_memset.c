/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:35:02 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/08 15:46:33 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)b;
	while (i < len)
	{
		temp[i] = c;
		i++;
	}
	return (b);
}
