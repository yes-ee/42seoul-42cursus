/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:46:04 by yeselee           #+#    #+#             */
/*   Updated: 2022/08/21 15:46:04 by yeselee          ###   ########.fr       */
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
	if (*(*buffer_backup + i) == '\n')	//개행으로 끝난 경우
	{
		i++;
		*line = gnl_substr(*buffer_backup, 0, i);
		next_backup = gnl_strdup(*buffer_backup + i);	//
	}
	else	//널 문자로 끝난 경우
		*line = gnl_strdup(*buffer_backup);
	free_ptr(buffer_backup);
	return (next_backup);
}

static int	read_line(int fd, char **buffer, char **buffer_backup, char **line)	//개행 또는 파일 끝나기 전까지 읽는 함수
{
	int		bytes_read;
	char	*temporary;

	bytes_read = 1;
	while (!gnl_strchr(*buffer_backup, '\n') && bytes_read)	//개행까지 읽어서 버퍼_백업에 저장
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		temporary = *buffer_backup;
		*buffer_backup = gnl_strjoin(temporary, *buffer);	//이전 문자열과 버퍼 사이즈만큼 새로 읽은 문자열을 합쳐줌
		free(temporary);
	}
	free_ptr(buffer);	//더이상 읽을 필요 없으니까 버퍼 반환
	*buffer_backup = get_line(buffer_backup, line);	//
	if (!(**line))
		free_ptr(line);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer_backup;	//
	char		*buffer;	//read로 읽은 값 저장할 버퍼
	char		*line;	//전체 문자열 저장

	if (fd < 0 || BUFFER_SIZE <= 0)	//인자가 잘못된 경우 오류
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)	//malloc 잘못된 경우 오류
		return (NULL);
	if (read(fd, buffer, 0) < 0)	//read에서 에러난 경우 오류
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer_backup)	//처음일 경우 - static은 초기값 0
		buffer_backup = gnl_strdup("");
	if (!read_line(fd, &buffer, &buffer_backup, &line) && !line)
		return (NULL);
	return (line);
}
