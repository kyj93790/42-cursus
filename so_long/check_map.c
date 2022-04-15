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

// void	check_outline(t_map *map_info)
// {
// 	t_ull	i;
// }

void	check_map(t_map *map_info)
{
	get_map_size(map_info);
	// check_outline(map_info);
	// 내부 부분 0, 1, C, E, P가 아니면 에러
	// C, E, P 하나 있어야 함.
	// P는 하나 아니면 에러로 처리

}