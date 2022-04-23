#include "so_long.h"

// 이동가능성 체크 함수
//		벽이 아닌 이상 다 이동이 가능하다 !
// 이동 불가능 시
//		현 위치 재세팅 (캐릭터의 방향을 바꿔주기 위해)
// 이동 가능 시
//		기존 위치 재세팅 (캐릭터만 제거)
//		new 위치가 수집품
//			map에서 수집품도 제거
//			cnt++
//		new 위치가 exit
//			수집품을 모두 모았다면 game finish
//		새 위치 print

void	refresh_curr_pos(t_game *game, t_ull curr_x, t_ull curr_y)
{
	put_tile(game, curr_y, curr_x);
	if (game->map[curr_y][curr_x] == 'E')
	{
		if (game->cnt == game->num_of_c)
			put_exit(game, curr_y, curr_x, 1);
		else
			put_exit(game, curr_y, curr_x, 0);
	}
}

void	move_to_new_pos(t_game *game, t_ull new_dir, t_ull new_x, t_ull new_y)
{
	game->loc.dir = new_dir;
	if (game->map[new_y][new_x] != '1')
	{
		game->loc.x = new_x;
		game->loc.y = new_y;
		(game->move)++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->character[game->loc.dir][game->move % 4].img_ptr, 64 * game->loc.x, 64 * game->loc.y);
}

void	check_new_pos(t_game *game)
{
	if (game->map[game->loc.y][game->loc.x] == 'E')
	{
		if (game->cnt == game->num_of_c)
		{
			free_game(game);
			printf("SUCCESS !\n");
			exit(EXIT_SUCCESS);
		}
	}
	else if (game->map[game->loc.y][game->loc.x] == 'C')
	{
		(game->cnt)++;
		game->map[game->loc.y][game->loc.x] = '0';
		put_tile(game, game->loc.y, game->loc.x);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->character[game->loc.dir][game->move % 4].img_ptr, 64 * game->loc.x, 64 * game->loc.y);
		if (game->cnt == game->num_of_c)
			put_exits(game, 1);
	}
}

int	press_key(int key_in, t_game *game)
{
	if (key_in == KEY_ESC)
	{
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	printf("key in : %d\n", key_in);
	if (key_in == KEY_W || key_in == KEY_A || key_in == KEY_S || key_in == KEY_D)
	{
		refresh_curr_pos(game, game->loc.x, game->loc.y);
		if (key_in == KEY_W)
			move_to_new_pos(game, 0, game->loc.x, game->loc.y - 1);
		else if (key_in == KEY_A)
			move_to_new_pos(game, 1, game->loc.x - 1, game->loc.y);
		else if (key_in == KEY_S)
			move_to_new_pos(game, 2, game->loc.x, game->loc.y + 1);
		else if (key_in == KEY_D)
			move_to_new_pos(game, 3, game->loc.x + 1, game->loc.y);
		check_new_pos(game);
	}
	printf("game->cnt : %llu\n", game->cnt);
	printf("(x, y): (%llu, %llu)\n", game->loc.x, game->loc.y);
	return (0);
}