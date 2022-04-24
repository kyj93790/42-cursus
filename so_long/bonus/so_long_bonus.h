/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:03:03 by yejin             #+#    #+#             */
/*   Updated: 2022/04/24 16:25:39 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"

# define X_EVENT_PRESS_KEY 2
# define X_EVENT_RED_CROSS 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef unsigned long long	t_ull;

typedef struct s_loc
{
	t_ull	dir;
	t_ull	x;
	t_ull	y;
}	t_loc;

typedef struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_ull	height;
	t_ull	width;
	char	**map;
	t_ull	num_of_c;
	t_ull	num_of_e;
	t_ull	num_of_p;
	t_img	tile;
	t_img	wall;
	t_img	collect;
	t_img	character[4][4];
	t_img	exit;
	t_img	enemy;
	t_loc	loc;
	t_ull	cnt;
	t_ull	move;
}	t_game;

void	exit_with_error(char *message);

void	check_filename(int argc, char *argv[]);
int		get_file_size(char *filename);
char	*read_file(char *filename);

void	free_game(t_game *game);
void	check_map(t_game *game);

void	start_game(t_game *game);
void	put_tiles(t_game *game);
void	put_walls(t_game *game);
void	put_collectibles(t_game *game);
void	put_exits(t_game *game, int flag);
void	put_enemys(t_game *game);

void	put_tile(t_game *game, t_ull i, t_ull j);
void	put_wall(t_game *game, t_ull i, t_ull j);
void	put_collectible(t_game *game, t_ull i, t_ull j);
void	put_exit(t_game *game, t_ull i, t_ull j, int flag);
void	put_enemy(t_game *game, t_ull i, t_ull j);

void	load_character_up_img(t_game *game);
void	load_character_left_img(t_game *game);
void	load_character_down_img(t_game *game);
void	load_character_right_img(t_game *game);
void	load_character_img(t_game *game);

int		press_key(int key_in, t_game *game);
int		press_red_cross(t_game *game);

void	print_movements(t_game *game);

#endif