/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:46:04 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/30 11:09:10 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*get_line(char **buffer_backup, char **line)
{
	char	*next_backup;
	int		i;

	i = 0;
	next_backup = NULL;
	while (*(*buffer_backup + i) != '\n' && *(*buffer_backup + i) != '\0')
		i++;
	if (*(*buffer_backup + i) == '\n')
	{
		i++;
		*line = gnl_substr(*buffer_backup, 0, i);
		next_backup = gnl_strdup(*buffer_backup + i);
	}
	else
		*line = gnl_strdup(*buffer_backup);
	free_ptr(buffer_backup);
	return (next_backup);
}

static int	read_line(int fd, char **buffer, char **buffer_backup, char **line)
{
	int		bytes_read;
	char	*temporary;

	bytes_read = 1;
	while (!gnl_strchr(*buffer_backup, '\n') && bytes_read)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		temporary = *buffer_backup;
		*buffer_backup = gnl_strjoin(temporary, *buffer);
		free(temporary);
	}
	free_ptr(buffer);
	*buffer_backup = get_line(buffer_backup, line);
	if (!(**line))
		free_ptr(line);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer_backup;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer_backup)
		buffer_backup = gnl_strdup("");
	if (!read_line(fd, &buffer, &buffer_backup, &line) && !line)
		return (NULL);
	return (line);
}
