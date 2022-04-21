#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"

# define X_EVENT_PRESS_KEY 2
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef unsigned long long	t_ull;

typedef struct s_loc
{
	t_ull	x;
	t_ull	y;
}	t_loc;

typedef struct s_game
{
	t_ull 	height;
	t_ull 	width;
	char	**map;
	t_ull	num_of_c;
	t_ull	num_of_e;
	t_ull	num_of_p;
	t_loc	loc;
}	t_game;

typedef struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_img;

void	exit_with_error(char *message);

void	check_filename(int argc, char *argv[]);
int		get_file_size(char *filename);
char	*read_file(char *filename);

void	free_map(t_game *game);
void	check_map(t_game *game);

void	init_game(t_game *game);

#endif