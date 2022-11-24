/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:58:21 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/25 00:58:22 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_img(t_map *map, void *obj, int w, int h)
{
	mlx_put_image_to_window(map->mlx, map->win, obj, w, h);
}

static void	setting_img_add(t_map *map, int hei, int wid)
{
	int	h64;
	int	w64;

	h64 = hei * 64;
	w64 = wid * 64;
	put_img(map, map->obj->land[0].pt, w64, h64);
	if (map->map_line[hei * map->width + wid] == '1')
		put_img(map, map->obj->tree[0].pt, w64, h64);
	else if (map->map_line[hei * map->width + wid] == 'C')
		put_img(map, map->obj->item[0].pt, w64, h64);
	else if (map->map_line[hei * map->width + wid] == 'P')
		put_img(map, map->obj->ss[0].pt, w64 + 16, h64 + 16);
	else if (map->map_line[hei * map->width + wid] == 'T')
		put_img(map, map->obj->teacher[0].pt, w64 + 16, h64 + 16);
	else if (map->map_line[hei * map->width + wid] == 'E')
	{
		put_img(map, map->obj->land[0].pt, w64, h64);
		if (map->c_items == map->all_items)
			put_img(map, map->obj->door[1].pt, w64 + 16, h64 + 16);
		else
			put_img(map, map->obj->door[0].pt, w64 + 16, h64 + 16);
	}
}

void	setting_img(t_map *map)
{
	int	hei;
	int	wid;

	hei = -1;
	while (++hei < map->height)
	{
		wid = -1;
		while (++wid < map->width)
			setting_img_add(map, hei, wid);
	}	
}
