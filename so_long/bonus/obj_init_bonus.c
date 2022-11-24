/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:58:47 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/25 00:58:48 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	img_init(t_map *map, t_img *img, int i, char *xpm)
{
	int	wd;
	int	hg;

	img[i].pt = mlx_xpm_file_to_image(map->mlx, xpm, &wd, &hg);
}

void	obj_move_init(t_map *map)
{
	map->obj = (t_obj *)malloc(sizeof(t_obj));
	if (!map->obj)
		return ;
	img_init(map, map->obj->sw, 0, "./img/s10.xpm");
	img_init(map, map->obj->sw, 1, "./img/s11.xpm");
	img_init(map, map->obj->sw, 2, "./img/s12.xpm");
	img_init(map, map->obj->ss, 0, "./img/s1.xpm");
	img_init(map, map->obj->ss, 1, "./img/s2.xpm");
	img_init(map, map->obj->ss, 2, "./img/s3.xpm");
	img_init(map, map->obj->sa, 0, "./img/s4.xpm");
	img_init(map, map->obj->sa, 1, "./img/s5.xpm");
	img_init(map, map->obj->sa, 2, "./img/s6.xpm");
	img_init(map, map->obj->sd, 0, "./img/s7.xpm");
	img_init(map, map->obj->sd, 1, "./img/s8.xpm");
	img_init(map, map->obj->sd, 2, "./img/s9.xpm");
	img_init(map, map->obj->item, 0, "./img/it.xpm");
	img_init(map, map->obj->door, 0, "./img/d1.xpm");
	img_init(map, map->obj->door, 1, "./img/d2.xpm");
	img_init(map, map->obj->tree, 0, "./img/tr1.xpm");
	img_init(map, map->obj->land, 0, "./img/ld.xpm");
	img_init(map, map->obj->teacher, 0, "./img/t1.xpm");
}
