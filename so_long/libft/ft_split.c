/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:35:55 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/15 15:58:33 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_malloc_arr(char **arr, char const *str, size_t len, size_t start)
{
	size_t	j;

	j = 0;
	*arr = malloc(sizeof(char) * len + 1);
	if (!(*arr))
		return (1);
	while (j < len)
	{
		(*arr)[j] = str[start + j];
		j++;
	}
	(*arr)[j] = '\0';
	return (0);
}

static int	ft_free_arr(char **arr, int count)
{
	while (count--)
		free(arr[count]);
	free(arr);
	return (1);
}

static int	ft_putstr_arr(char **arr, char const *str, char c, int count)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (i - start > 0)
				if (ft_malloc_arr(&(arr[count++]), str, i - start, start) == 1)
					return (ft_free_arr(arr, count - 1));
			start = i + 1;
		}
		i++;
	}
	if (i - start > 0)
		if (ft_malloc_arr(&(arr[count++]), str, i - start, start) == 1)
			return (ft_free_arr(arr, count - 1));
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_count;
	size_t	count;
	char	**arr;

	i = 0;
	word_count = 0;
	count = 0;
	if ((s[0] != c) && s[0] != '\0')
		word_count++;
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1] != '\0'))
			word_count++;
		i++;
	}
	arr = malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		return (0);
	if (ft_putstr_arr(arr, s, c, count) == 1)
		return (0);
	arr[word_count] = 0;
	return (arr);
}
