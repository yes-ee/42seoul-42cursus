/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:54:20 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/24 23:36:59 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	first_line_check(char *line, t_map *map)
{
	int		width;
	int		size;
	char	**line_split;

	size = ft_strlen(line);
	if (size <= 1)
		print_error("map error -> size error");
	width = 0;
	while (width < size -1)
	{
		if (line[width] != '1')
			print_error("map error -> not surrounded top wall");
		width++;
	}
	line_split = ft_split(line, '\n');
	map->map_line = ft_strdup(line_split[0]);
	free_all(line_split);
	if (map-> width != size - 1)
		print_error("map error -> map is not rectangular");
}

void	middle_line_check(char *line, t_map *map)
{
	int		size;
	int		i;
	char	**line_split;

	size = ft_strlen(line);
	if (size - 1 != map->width || line[0] != '1' || line[size - 2] != '1')
		print_error("map error -> not surrounded left or right wall");
	i = 0;
	while (i < size - 1)
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'C' || \
			line[i] == 'E' || line[i] == 'P'))
			print_error("map error -> invalid component");
		i++;
	}
	line_split = ft_split(line, '\n');
	map->map_line = ft_strjoin(map->map_line, line_split[0]);
	free_all(line_split);
	if (map-> width != size - 1)
		print_error("map error -> map is not rectangul");
}

void	last_line_check(char *line, t_map *map)
{
	int		size;
	int		i;
	char	**line_split;

	i = 0;
	size = ft_strlen(line);
	if (map->width != size - 1)
		print_error("map error -> last line error");
	while (i < size -1)
	{
		if (line[i] != '1')
			break ;
		i++;
	}
	line_split = ft_split(line, '\n');
	map->map_line = ft_strjoin(map->map_line, line_split[0]);
	free_all(line_split);
	if (map->width != size - 1)
		print_error("map error -> map is not rectangular");
}

int	map_size_check(int fd, t_map *map)
{
	int		size;
	char	*line;

	if (fd < 0)
		print_error("map error -> not valid file descriptor");
	size = 0;
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		size++;
	}
	free(line);
	map->height = size;
	if (map -> height <= 2)
		print_error("map error -> not valid map size");
	return (size - 2);
}

void	map_init(t_map *map, char *argv)
{
	int		fd;
	int		middle_size;
	char	*line;

	fd = fd_check(argv);
	middle_size = map_size_check(fd, map);
	close(fd);
	fd = fd_check(argv);
	line = get_next_line(fd);
	first_line_check(line, map);
	free(line);
	while (middle_size--)
	{
		line = get_next_line(fd);
		middle_line_check(line, map);
		free(line);
	}
	line = get_next_line(fd);
	last_line_check(line, map);
	free(line);
	close(fd);
}
