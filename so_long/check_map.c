#include "so_long.h"

void	free_map(t_map *map_info)
{
	t_ull	i;

	i = 0;
	while (map_info->map[i])
		free(map_info->map[i++]);
	free(map_info->map);
}

void	get_map_size(t_map *map_info)
{
	t_ull	i;

	i = 0;
	while (map_info->map[i])
		i++;
	map_info->height = i;
	map_info->width = ft_strlen(map_info->map[0]);
	if (map_info->height < 3 || map_info->width < 3)
	{
		free_map(map_info);
		exit_with_error("Failure by map size");
	}
	i = 0;
	while (map_info->map[i])
	{
		if (ft_strlen(map_info->map[i]) != map_info->width)
		{
			free_map(map_info);
			exit_with_error("Failure by feature of map");
		}
		i++;
	}
}

void	check_outline(t_map *map_info)
{
	t_ull	i;
	t_ull	h;
	t_ull	w;

	h = map_info->height;
	w = map_info->width;
	i = -1;
	while (++i < h)
	{
		if (map_info->map[i][0] != '1' || map_info->map[i][w - 1] != '1')
		{
			free_map(map_info);
			exit_with_error("Failure by outline of map");
		}
	}
	i = -1;
	while (++i < w)
	{
		if (map_info->map[0][i] != '1' || map_info->map[h - 1][i] != '1')
		{
			free_map(map_info);
			exit_with_error("Failure by outline of map");
		}
	}
}

void	check_contents(t_map *map_info)
{
	t_ull	i;
	t_ull	j;

	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
		{
			if (map_info->map[i][j] == 'C')
				(map_info->num_of_c)++;
			else if (map_info->map[i][j] == 'E')
				(map_info->num_of_e)++;
			else if (map_info->map[i][j] == 'P')
				(map_info->num_of_p)++;
			else if (map_info->map[i][j] != '0' || map_info->map[i][j] != '1')
			{
				free_map(map_info);
				exit_with_error("Failure by contents of map");
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_map *map_info)
{
	get_map_size(map_info);
	check_outline(map_info);
	check_contents(map_info);
	if (map_info->num_of_c < 1)
	{
		free_map(map_info);
		exit_with_error("Failure by number of collectible");
	}
	if (map_info->num_of_e < 1)
	{
		free_map(map_info);
		exit_with_error("Failure by number of exit");
	}
	if (map_info->num_of_p != 1)
	{
		free_map(map_info);
		exit_with_error("Failure by number of starting position");
	}
}