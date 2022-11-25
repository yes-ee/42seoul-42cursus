/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:54:28 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/25 22:26:37 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_map *map, void *obj, int w, int h)
{
	mlx_put_image_to_window(map->mlx, map->win, obj, w, h);
}

void	setting_img(t_map *map)
{
	int	hei;
	int	wid;
	int	h64;
	int	w64;

	hei = -1;
	while (++hei < map->height)
	{
		wid = -1;
		while (++wid < map->width)
		{
			h64 = hei * 64;
			w64 = wid * 64;
			put_img(map, map->obj->ld, w64, h64);
			if (map->map_line[hei * map->width + wid] == '1')
				put_img(map, map->obj->tr, w64, h64);
			else if (map->map_line[hei * map->width + wid] == 'C')
				put_img(map, map->obj->it, w64, h64);
			else if (map->map_line[hei * map->width + wid] == 'P')
				put_img(map, map->obj->s1, w64 + 16, h64 + 16);
			else if (map->map_line[hei * map->width + wid] == 'E')
				put_img(map, map->obj->d1, w64 + 16, h64 + 16);
		}
	}	
}

void	mlx_connect(t_map *map)
{
	map->mlx = mlx_init();
	if (map->mlx == 0)
		exit(1);
	map->win = mlx_new_window(map->mlx, map->width * 64, \
	map->height * 64, "so_long");
	if (map->win == 0)
		exit(1);
}
