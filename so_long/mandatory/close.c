/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:54:15 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/24 23:00:57 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
