/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:57:58 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/25 00:58:00 by yeselee          ###   ########.fr       */
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
	printf("Error\n%s", msg);
	exit(1);
}
