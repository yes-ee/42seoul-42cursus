/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:56:12 by yeselee           #+#    #+#             */
/*   Updated: 2022/11/24 20:56:14 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# include <mlx.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2

typedef struct s_img
{
	void		*pt;
}				t_img;

typedef struct s_obj
{
	t_img		item[1];
	t_img		door[2];
	t_img		sw[3];
	t_img		ss[3];
	t_img		sa[3];
	t_img		sd[3];
	t_img		tree[1];
	t_img		land[1];
	t_img		teacher[1];
}				t_obj;

typedef struct s_map
{
	int				x;
	int				y;
	int				width;
	int				height;
	int				all_items;
	int				c_items;
	int				walk_cnt;
	int				map_size;
	char			*map_line;
	void			*mlx;
	void			*win;
	struct s_obj	*obj;
}					t_map;

/* main.c */
int		fd_check(char *argv);
void	arg_check(char *argv);
void	objs(t_map *map);
int		main(int argc, char **argv);

/* close_bonus.c */
int		exit_game(t_map *game);
void	print_error(char *msg);

/* map_check.c */
void	first_line_check(char *line, t_map *map);
void	middle_line_check(char *line, t_map *map);
void	last_line_check(char *line, t_map *map);
int		map_size_check(int fd, t_map *map);
void	map_init(t_map *map, char *argv);

/* mlx_utils.c */
void	put_img(t_map *map, void *obj, int w, int h);
void	setting_img(t_map *map);

/* move_d_bonus.c */
void	move_d(t_map *map);
void	setting_img_d2(t_map *map, int hei, int wid);
void	put_img_rd_d(t_map *map, int w64, int h64);
void	setting_img_d3(t_map *map);
void	setting_img_d1(t_map *map);

/* move_s_bonus.c */
void	move_s(t_map *map);
void	setting_img_s2(t_map *map, int hei, int wid);
void	put_img_rd_s(t_map *map, int w64, int h64);
void	setting_img_s3(t_map *map);
void	setting_img_s1(t_map *map);

/* move_a_bonus.c */
void	move_a(t_map *map);
void	setting_img_a2(t_map *map, int hei, int wid);
void	put_img_rd_a(t_map *map, int w64, int h64);
void	setting_img_a3(t_map *map);
void	setting_img_a1(t_map *map);

/* move_w_bonus.c */
void	move_w(t_map *map);
void	setting_img_w2(t_map *map, int hei, int wid);
void	put_img_rd_w(t_map *map, int w64, int h64);
void	setting_img_w3(t_map *map);
void	setting_img_w1(t_map *map);

/* obj_init.c */
void	obj_move_init(t_map *map);
void	img_init(t_map *map, t_img *img, int i, char *xpm);

/* utils.c */
int		create_trgb(int t, int r, int g, int b);
void	free_all(char **split);
int		press_key(int key_code, t_map *map);

/* enemy_move_bonus.c */
void	make_enemy(t_map *map);
void	move_enemy(t_map *map);

/* enemy_move2.c */
void	enemy_move_0(t_map *map, int i);
void	enemy_move_1(t_map *map, int i);
void	enemy_move_2(t_map *map, int i);
void	enemy_move_3(t_map *map, int i);

#endif
