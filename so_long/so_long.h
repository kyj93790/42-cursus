#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"

typedef unsigned long long	t_ull;

typedef struct s_map {
	t_ull 	height;
	t_ull 	width;
	char	**map;
	t_ull	num_of_c;
	t_ull	num_of_e;
	t_ull	num_of_p;
}	t_map;

#endif