/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:54:32 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/25 00:51:52 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_cnt(t_map *map)
{
	char	*cnt;

	cnt = ft_itoa(map->walk_cnt);
	write(1, cnt, ft_strlen(cnt));
	write(1, "\n", 1);
	free(cnt);
}

void	move_d(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map->map_line))
	{
		if (map -> map_line[i] == 'P')
			break ;
		i++;
	}
	if (map->map_line[i + 1] == '1')
		return ;
	if (map->map_line[i + 1] == 'C')
		map->c_items++;
	if (map->map_line[i + 1] == 'E' && map->all_items == map->c_items)
		exit_game(map);
	if (map->map_line[i + 1] == 'E' && map->all_items != map->c_items)
		return ;
	else if (map -> map_line[i + 1] != '1' || map -> map_line[i + 1] != 'E')
	{
		map->map_line[i + 1] = 'P';
		map->map_line[i] = '0';
		map->walk_cnt++;
		print_cnt(map);
		setting_img(map);
	}
}

void	move_a(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map->map_line))
	{
		if (map -> map_line[i] == 'P')
			break ;
		i++;
	}
	if (map->map_line[i - 1] == '1')
		return ;
	if (map->map_line[i - 1] == 'C')
		map->c_items++;
	if (map->map_line[i - 1] == 'E' && map->all_items == map->c_items)
		exit_game(map);
	if (map->map_line[i - 1] == 'E' && map->all_items != map->c_items)
		return ;
	else if (map -> map_line[i - 1] != '1' || map -> map_line[i + 1] != 'E')
	{
		map -> map_line[i - 1] = 'P';
		map -> map_line[i] = '0';
		map->walk_cnt++;
		print_cnt(map);
		setting_img(map);
	}
}

void	move_w(t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(map->map_line))
		if (map -> map_line[i] == 'P')
			break ;
	if (map->map_line[i - map->width] == '1')
		return ;
	if (map->map_line[i - map->width] == 'C')
		map->c_items++;
	if (map->map_line[i - map->width] == 'E' && map->all_items == map->c_items)
		exit_game(map);
	if (map->map_line[i - map->width] == 'E' && map->all_items != map->c_items)
		return ;
	else if (map -> map_line[i - map->width] != '1' || \
	map -> map_line[i + 1] != 'E')
	{
		map -> map_line[i - map->width] = 'P';
		map -> map_line[i] = '0';
		map->walk_cnt++;
		print_cnt(map);
		setting_img(map);
	}
}

void	move_s(t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(map->map_line))
		if (map -> map_line[i] == 'P')
			break ;
	if (map->map_line[i + map->width] == '1')
		return ;
	if (map->map_line[i + map->width] == 'C')
		map->c_items++;
	if (map->map_line[i + map->width] == 'E' && map->all_items == map->c_items)
		exit_game(map);
	if (map->map_line[i + map->width] == 'E' && map->all_items != map->c_items)
		return ;
	else if (map -> map_line[i + map->width] != '1' || \
	map -> map_line[i + 1] != 'E')
	{
		map -> map_line[i + map->width] = 'P';
		map -> map_line[i] = '0';
		map->walk_cnt++;
		print_cnt(map);
		setting_img(map);
	}
}
