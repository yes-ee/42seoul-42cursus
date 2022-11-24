/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:58:56 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/25 00:58:56 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	free_all(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int	press_key(int key_code, t_map *map)
{
	if (key_code == KEY_ESC)
		exit_game(map);
	if (key_code == KEY_W)
		move_w(map);
	if (key_code == KEY_A)
		move_a(map);
	if (key_code == KEY_S)
		move_s(map);
	if (key_code == KEY_D)
		move_d(map);
	return (0);
}
