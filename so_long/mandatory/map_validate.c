/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:16:03 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/29 23:23:03 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <string.h>

void	malloc_arr(t_map *map)
{
	int		i;
	char	*start;

	i = -1;
	map->valid_map = malloc(sizeof(char *) * (map->height + 1));
	map->visit = malloc(sizeof(char *) * (map->height + 1));
	if (!map->valid_map || !map->visit)
		print_error("map error -> malloc failure");
	while (++i < map->height)
	{
		start = map->map_line + map->width * i;
		map->valid_map[i] = ft_strndup(start, map->width);
		map->visit[i] = malloc(sizeof(char) * (map->width + 1));
		if (!map->valid_map[i] || !map->visit[i])
			print_error("map error -> malloc failure");
		memset(map->visit[i], '1', sizeof(char) * map->width);
		map->visit[i][map->width] = 0;
	}
	map->valid_map[i] = 0;
	map->visit[i] = 0;
}

int	check_player(t_map *map)
{
	int	player;

	player = -1;
	while (map->map_line[++player])
		if (map->map_line[player] == 'P')
			break ;
	return (player);
}

void	init_dir(t_dir *dir)
{
	dir->dx[0] = 0;
	dir->dx[1] = 0;
	dir->dx[2] = 1;
	dir->dx[3] = -1;
	dir->dy[0] = 1;
	dir->dy[1] = -1;
	dir->dy[2] = 0;
	dir->dy[3] = 0;
}

void	dfs(int x, int y, t_map *map, t_dir dir)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = -1;
	if (0 > x || x >= map->height || 0 > y || y >= map->width || \
	map->visit[x][y] == '0' || map->valid_map[x][y] == '1')
		return ;
	map->visit[x][y] = '0';
	if (map->valid_map[x][y] == 'E')
	{
		map->e_check++;
		return ;
	}
	if (map->valid_map[x][y] == 'C')
		map->c_check++;
	while (++i < 4)
		dfs(x + dir.dx[i], y + dir.dy[i], map, dir);
}

void	map_validation(t_map *map)
{
	int		player;
	t_dir	dir;

	malloc_arr(map);
	player = check_player(map);
	init_dir(&dir);
	dfs(player / map->width, player % map->width, map, dir);
	printf("c_check : %d % d\n", map->c_check, map->e_check);
	if (map->c_check != map->all_items || map->e_check != 1)
	{
		free_all(map->valid_map);
		free_all(map->visit);
		print_error("map error -> not valid path");
	}
}
