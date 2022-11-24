/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_rd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:58:52 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/25 00:58:52 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_img_rd_a(t_map *map, int w64, int h64)
{
	int	rd;

	map->x = map->x - 8;
	rd = map->x % 3;
	put_img(map, map->obj->sa[rd].pt, w64, h64);
}

void	put_img_rd_d(t_map *map, int w64, int h64)
{
	int	rd;

	map->x = map->x + 8;
	rd = map->x % 3;
	put_img(map, map->obj->sd[rd].pt, w64, h64);
}

void	put_img_rd_s(t_map *map, int w64, int h64)
{
	int	rd;

	map->y = map->y + 8;
	rd = map->y % 3;
	put_img(map, map->obj->ss[rd].pt, w64, h64);
}

void	put_img_rd_w(t_map *map, int w64, int h64)
{
	int	rd;

	map->y = map->y - 8;
	rd = map->y % 3;
	put_img(map, map->obj->sw[rd].pt, w64, h64);
}
