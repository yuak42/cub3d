#include "cub3d.h"

void	print_texture_paths(t_game *game)
{
	ft_printf("Texture paths:\n\n");
	ft_printf("NO -> %s\n", game->texture.no);
	ft_printf("SO -> %s\n", game->texture.so);
	ft_printf("WE -> %s\n", game->texture.we);
	ft_printf("EA -> %s\n", game->texture.ea);
	
	ft_printf("F -> r: %d, g: %d, b: %d\n", game->texture.f.r, game->texture.f.g, game->texture.f.b);
	ft_printf("C -> r: %d, g: %d, b: %d\n", game->texture.c.r, game->texture.c.g, game->texture.c.b);

	ft_printf("-----------------------------------------------------\n\n");
}
