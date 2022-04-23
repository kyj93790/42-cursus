#include "so_long.h"

// 추후 mlx_ptr, win_ptr도 game안으로 합칠 것.
// 어디에서나 exit하기 전에 할당된 모든 메모리를 해제할 수 있도록 할 것
void	load_character_up_img(void *mlx_ptr, void *win_ptr, t_game *game)
{
	game->character[0][0].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/up0.xpm", &(game->character[0][0].width), &(game->character[0][0].height));
	game->character[0][1].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/up1.xpm", &(game->character[0][1].width), &(game->character[0][1].height));
	game->character[0][2].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/up2.xpm", &(game->character[0][2].width), &(game->character[0][2].height));
	game->character[0][3].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/up3.xpm", &(game->character[0][3].width), &(game->character[0][3].height));
	if (!(game->character[0][0].img_ptr) || !(game->character[0][1].img_ptr) || !(game->character[0][2].img_ptr) || !(game->character[0][3].img_ptr))
	{
		free_game(game);
		exit_with_error("Failure in loading character's up image");
	}
}

void	load_character_left_img(void *mlx_ptr, void *win_ptr, t_game *game)
{
	game->character[1][0].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/left0.xpm", &(game->character[1][0].width), &(game->character[1][0].height));
	game->character[1][1].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/left1.xpm", &(game->character[1][1].width), &(game->character[1][1].height));
	game->character[1][2].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/left2.xpm", &(game->character[1][2].width), &(game->character[1][2].height));
	game->character[1][3].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/left3.xpm", &(game->character[1][3].width), &(game->character[1][3].height));
	if (!(game->character[1][0].img_ptr) || !(game->character[1][1].img_ptr) || !(game->character[1][2].img_ptr) || !(game->character[1][3].img_ptr))
	{
		free_game(game);
		exit_with_error("Failure in loading character's left image");
	}
}

void	load_character_down_img(void *mlx_ptr, void *win_ptr, t_game *game)
{
	game->character[2][0].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/down0.xpm", &(game->character[2][0].width), &(game->character[2][0].height));
	game->character[2][1].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/down1.xpm", &(game->character[2][1].width), &(game->character[2][1].height));
	game->character[2][2].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/down2.xpm", &(game->character[2][2].width), &(game->character[2][2].height));
	game->character[2][3].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/down3.xpm", &(game->character[2][3].width), &(game->character[2][3].height));
	if (!(game->character[2][0].img_ptr) || !(game->character[2][1].img_ptr) || !(game->character[2][2].img_ptr) || !(game->character[2][3].img_ptr))
	{
		free_game(game);
		exit_with_error("Failure in loading character's down image");
	}
}

void	load_character_right_img(void *mlx_ptr, void *win_ptr, t_game *game)
{
	game->character[3][0].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/right0.xpm", &(game->character[3][0].width), &(game->character[3][0].height));
	game->character[3][1].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/right1.xpm", &(game->character[3][1].width), &(game->character[3][1].height));
	game->character[3][2].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/right2.xpm", &(game->character[3][2].width), &(game->character[3][2].height));
	game->character[3][3].img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/right3.xpm", &(game->character[3][3].width), &(game->character[3][3].height));
	if (!(game->character[3][0].img_ptr) || !(game->character[3][1].img_ptr) || !(game->character[3][2].img_ptr) || !(game->character[3][3].img_ptr))
	{
		free_game(game);
		exit_with_error("Failure in loading character's right image");
	}
}

void	load_character_img(void *mlx_ptr, void *win_ptr, t_game *game)
{
	load_character_up_img(mlx_ptr, win_ptr, game);
	load_character_left_img(mlx_ptr, win_ptr, game);
	load_character_down_img(mlx_ptr, win_ptr, game);
	load_character_right_img(mlx_ptr, win_ptr, game);
}