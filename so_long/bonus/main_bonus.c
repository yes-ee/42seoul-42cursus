/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:58:13 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/25 00:58:14 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	fd_check(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		print_error("failed open.\n");
	return (fd);
}

void	arg_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (ft_strncmp(argv + i - 4, ".ber", 4) != 0)
		print_error("not vaild extension\n");
}

void	objs(t_map *map)
{
	int	i;
	int	exits;
	int	p_start;

	i = 0;
	exits = 0;
	p_start = 0;
	map->x = 16;
	map->y = 16;
	while (map->map_line[i])
	{
		if (map->map_line[i] == 'C')
			map->all_items++;
		else if (map->map_line[i] == 'E')
			exits++;
		else if (map ->map_line[i] == 'P')
			p_start++;
		i++;
	}
	if (map->all_items < 1 || exits < 1 || p_start != 1)
		print_error("map error -> objets error");
	map->map_size = ft_strlen(map->map_line);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		print_error("argument error -> ./so_long <map_name>.ber\n");
	ft_memset(&map, 0, sizeof(t_map));
	arg_check(argv[1]);
	map_init(&map, argv[1]);
	objs(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width * 64, \
	map.height * 64, "so_long");
	obj_move_init(&map);
	make_enemy(&map);
	setting_img(&map);
	mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &press_key, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
