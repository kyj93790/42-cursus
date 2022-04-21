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

typedef struct s_map {
	t_ull 	height;
	t_ull 	width;
	char	**map;
	t_ull	num_of_c;
	t_ull	num_of_e;
	t_ull	num_of_p;
}	t_map;

typedef struct s_loc {
	t_ull	x;
	t_ull	y;
}	t_loc;

void	exit_with_error(char *message);

void	check_filename(int argc, char *argv[]);
int		get_file_size(char *filename);
char	*read_file(char *filename);

void	free_map(t_map *map_info);
void	check_map(t_map *map_info);

void	start_game(t_map *map_info);

#endif