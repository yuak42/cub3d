#include "cub3d.h"

void	print_player_info(t_game *game)
{
	ft_printf("Player info:\n\n");
	printf("Player Position -> (%.3f,%.3f)\n", game->player.x, game->player.y);
	printf("Player direction -> (%.3f,%.3f)\n", game->player.dir_x, game->player.dir_y);
}