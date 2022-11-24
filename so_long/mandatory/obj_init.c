/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:54:40 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/24 20:54:41 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	obj_init(t_map *map)
{
	int	wd;
	int	hg;

	map->obj = (t_obj *)malloc(sizeof(t_obj));
	if (!map->obj)
		return ;
	map->obj->ld = mlx_xpm_file_to_image(map->mlx, "./img/ld.xpm", &wd, &hg);
	map->obj->tr = mlx_xpm_file_to_image(map->mlx, "./img/tr1.xpm", &wd, &hg);
	map->obj->it = mlx_xpm_file_to_image(map->mlx, "./img/it.xpm", &wd, &hg);
	map->obj->d1 = mlx_xpm_file_to_image(map->mlx, "./img/d2.xpm", &wd, &hg);
	map->obj->s1 = mlx_xpm_file_to_image(map->mlx, "./img/s1.xpm", &wd, &hg);
}
