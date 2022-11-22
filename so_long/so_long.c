/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 06:20:38 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/23 01:00:37 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define KEY_ESC 53
#define KEY_W   13
#define KEY_S   1

typedef struct s_param {
	int	x;
	int	y;
}	t_param;

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_param	param;

	param_init(&param);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	win_ptr = mlx_new_window(mlx_ptr, 1500, 700, "so_long_project");
	if (!win_ptr)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	mlx_key_hook(win, &key_press, &param);
	mlx_loop(mlx_ptr);
	return (0);
}
