#include "cub3d.h"

void	print_player_info(t_game *game)
{
	ft_printf("Player info:\n\n");
	ft_printf("Player Position -> (%d,%d)\n", game->player.x, game->player.y);
	ft_printf("Player direction -> (%d,%d)\n", (int) game->player.dir_x, (int) game->player.dir_y);
}