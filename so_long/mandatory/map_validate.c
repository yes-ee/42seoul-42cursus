/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:16:03 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/28 21:59:55 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
// #include<stdio.h>
// #include<string.h>
// #include<algorithm>
// #include<iostream>
// #include<vector>
// #include<string>
// #define inf 100000000
// using namespace std;


// int arr[26][26];
// int check[26][26];
// int dr[4] = { 0,0,1,-1 };
// int dc[4] = { 1,-1,0,0 };
// int n;
#include <string.h>

void	dfs(int x, int y, t_map *map, t_dir dir)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = -1;
	if (0 > x || x >= map->height || 0 > y || y >= map->width)
		return ;
	if (map->visit[x][y] == '0')
		return ;
	if (map->valid_map[x][y] == '1' || map->valid_map[x][y] == 'E')
		return ;
	printf("%d %d, %c\n", x, y, map->valid_map[x][y]);
	// for (int i = 0; i < map->height; i++)
	// {
	// 	for (int j = 0; j < map->width; j++)
	// 	{
			
	// 	}
	// }
	map->visit[x][y] = '0';
	if (map->valid_map[x][y] == 'C')
		map->c_check++;
	else if (map->valid_map[x][y] == 'E')
		map->e_check++;
	while (++i < 4)
		dfs(x + dir.dx[i], y + dir.dy[i], map, dir);
	// while (++i < 4)
	// {
	// 	nx = x + dir.dx[i];
	// 	ny = y + dir.dy[i];
	// 	if (0 <= nx && nx < map->width && 0 <= ny && ny < map->height && \
	// 	map->visit[nx][ny] == '1' && map->valid_map[nx][ny] != '1' && \
	// 	map->valid_map[nx][ny] != 'E')
	// 	{
	// 		if (map->valid_map[nx][ny] == 'C')
	// 			cnt+=dfs(nx, ny, map, dir)+1;
	// 		else
	// 			cnt+=dfs(nx, ny, map, dir);
	// 	}
	// 		// dfs(nx, ny, &map, dir);
	// }

	// for (int k = 0; k < 4; k++) {
	// 	int nr = dr + dir.dr[k], nc = c + dirdc[k];
	// 	if (0 <= nr && nr < n && 0 <= nc&& nc < n&&!check[nr][nc]&& arr[nr][nc]) {
	// 		cnt+=dfs(nr, nc, dir)+1;
	// 	}
	// }
	// return cnt;
}

void	map_validation(t_map *map)
{
	int		i;
	int		player;
	t_dir	dir;

	i = -1;
	map->valid_map = malloc(sizeof(char *) * (map->height + 1));
	map->visit = malloc(sizeof(char *) * (map->height + 1));
	if (!map->valid_map || !map->visit)
		print_error("map error -> malloc failure");
	while (++i < map->height)
	{
		map->valid_map[i] = ft_strndup(map->map_line + map->width * i, map->width);
		map->visit[i] = malloc(sizeof(char) * (map->width + 1));
		if (!map->valid_map[i] || !map->visit)
			print_error("map error -> malloc failure");
		memset(map->visit[i], '1', sizeof(char) * map->width);
		map->visit[map->width] = 0;
	}
	// map[height][width]
	// map[x][y]
	i = -1;
	int j = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			printf("%c", map->valid_map[i][j]);
		printf("\n");
	}
	i = -1;
	j = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			printf("%c", map->visit[i][j]);
		printf("\n");
	}
	map->valid_map[i] = 0;
	map->visit[i] = 0;
	player = -1;
	while (map->map_line[++player])
		if (map->map_line[player] == 'P')
			break ;
	dir.dx[0] = 0;
	dir.dx[1] = 0;
	dir.dx[2] = 1;
	dir.dx[3] = -1;
	dir.dy[0] = 1;
	dir.dy[1] = -1;
	dir.dy[2] = 0;
	dir.dy[3] = 0;
	printf("x : [%d], y = [%d]\n", player % map->width, player / map->width);
	dfs(player / map->width, player % map->width, map, dir);
	i = -1;
	j = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			printf("%c", map->visit[i][j]);
		printf("\n");
	}
}