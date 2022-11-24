/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:58:08 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/25 00:58:09 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	enemy_move_0(t_map *map, int i)
{
	if (map->map_line[i - map->width] == '0')
	{
		map->map_line[i] = '0';
		map->map_line[i - map->width] = 'T';
	}
}

void	enemy_move_1(t_map *map, int i)
{
	if (map->map_line[i + 1] == '0')
	{
		map->map_line[i] = '0';
		map->map_line[i + 1] = 'T';
	}
}

void	enemy_move_2(t_map *map, int i)
{
	if (map->map_line[i + map->width] == '0')
	{
		map->map_line[i] = '0';
		map->map_line[i + map->width] = 'T';
	}
}

void	enemy_move_3(t_map *map, int i)
{
	if (map->map_line[i - 1] == '0')
	{
		map->map_line[i] = '0';
		map->map_line[i - 1] = 'T';
	}
}
