/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 20:35:55 by yeselee           #+#    #+#             */
/*   Updated: 2022/05/12 23:40:56 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_sep(char *str, char c, int *sep)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			sep[i] = 1;
		else
			sep[i] = 0;
		i++;
	}
	sep[i] = 1;
}

void	ft_malloc_arr(char **arr, char *str, size_t str_len, size_t start)
{
	size_t	j;

	j = 0;
	*arr = malloc(sizeof(char) * (str_len + 1));
	while (j++ < str_len)
		(*arr)[j] = str[start + j];
	(*arr)[j] = '\0';
}

void	ft_putstr_arr(char **arr, char *str, int *sep)
{
	size_t	str_len;
	size_t	i;
	size_t	start;

	str_len = 0;
	i = 0;
	start = 0;
	while (str[i++] != '\0')
	{
		if (sep[i] == 0)
			str_len++;
		else if (str_len > 0)
		{
			ft_malloc_arr(arr, str, str_len, start);
			start = i + 1;
			str_len = 0;
			arr++;
		}
		else
			start = i + 1;
	}
	if (str_len > 0)
		ft_malloc_arr(arr, str, str_len, start);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_count;
	int		*sep;
	char	*arr;

	i = 0;
	word_count = 0;
	sep = malloc(sizeof(int) * (ft_strlen(s) + 1));
	ft_init_sep(s, c, sep);
	if (sep[0] == 0)
		word_count++;
	while (s[i] != '\0')
	{
		if (sep[i] == 1 && sep[i + 1] == 0)
			word_count++;
	}
	arr = malloc(sizeof(char *) * (word_count + 1));
	ft_putstr_arr(arr, s, sep);
	arr[word_count] = 0;
	return (arr);
}
