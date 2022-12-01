/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:57:58 by yeselee           #+#    #+#             */
/*   Updated: 2022/12/01 16:50:06 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	exit_game(t_map *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	print_error(char *msg)
{
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	exit(1);
}
