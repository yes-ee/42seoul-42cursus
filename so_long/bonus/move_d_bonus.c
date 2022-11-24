/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_d_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:58:35 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/25 00:58:36 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	setting_img_d2(t_map *map, int hei, int wid)
{
	int	h64;
	int	w64;

	h64 = hei * 64;
	w64 = wid * 64;
	if (map->map_line[hei * map->width + wid] == '1')
		put_img(map, map->obj->tree[0].pt, w64, h64);
	else if (map->map_line[hei * map->width + wid] == 'C')
		put_img(map, map->obj->item[0].pt, w64, h64);
	else if (map->map_line[hei * map->width + wid] == 'T')
		put_img(map, map->obj->teacher[0].pt, w64 + 16, h64 + 16);
	else if (map->map_line[hei * map->width + wid] == 'E')
	{
		if (map->c_items == 0)
			put_img(map, map->obj->door[1].pt, w64 + 16, h64 + 16);
		else
			put_img(map, map->obj->door[0].pt, w64 + 16, h64 + 16);
	}
}

void	setting_img_d3(t_map *map)
{
	int	hei;
	int	wid;
	int	h64;
	int	w64;

	hei = 0;
	while (hei < map->height)
	{
		wid = 0;
		while (wid < map->width)
		{
			if (map->map_line[hei * map->width + wid] == 'P')
			{
				h64 = hei * 64 + map->y;
				w64 = wid * 64 + map->x;
				put_img_rd_d(map, w64, h64);
			}
			wid++;
		}
		hei++;
	}
}

void	setting_img_d1(t_map *map)
{
	int		hei;
	int		wid;
	char	*walk_cnt;

	hei = 0;
	walk_cnt = ft_itoa(map->walk_cnt);
	while (hei < map->height)
	{
		wid = 0;
		while (wid < map->width)
		{
			put_img(map, map->obj->land[0].pt, wid * 64, hei * 64);
			setting_img_d2(map, hei, wid);
			wid++;
		}
		hei++;
	}
	setting_img_d3(map);
	mlx_string_put(map->mlx, map->win, 10, 10, \
		create_trgb(0, 255, 255, 255), walk_cnt);
	free(walk_cnt);
}

static int	move_d2(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < map->map_size)
		if (map->map_line[i] == 'P')
			break ;
	if (map->x == 48)
		if (map->map_line[i + 1] == '1')
			return (1);
	if (map->x == 64)
	{
		if (map->map_line[i + 1] == 'T')
			exit_game(map);
		if (map->map_line[i + 1] == 'E' && map->c_items == 0)
			exit_game(map);
		if (map->map_line[i + 1] == 'E' && map->c_items != 0)
			return (1);
		map->map_line[i + 1] = 'P';
		map->map_line[i] = '0';
		map->x = 0;
	}
	return (0);
}

void	move_d(t_map *map)
{
	int	i;

	i = 0;
	map->c_items = 0;
	while (i++ < map->map_size)
		if (map->map_line[i] == 'C')
			map->c_items++;
	if (move_d2(map))
		return ;
	map->walk_cnt++;
	move_enemy(map);
	setting_img_d1(map);
}
