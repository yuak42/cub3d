#include "data.h"
#include <stdio.h>
#include "cub3d.h"

void	print_texture_paths(t_game *game)
{
	printf("Texture paths:\n\n");
	printf("NO -> %s\n", game->texture.no);
	printf("SO -> %s\n", game->texture.so);
	printf("WE -> %s\n", game->texture.we);
	printf("EA -> %s\n", game->texture.ea);

	printf("F -> r: %d, g: %d, b: %d\n", game->texture.f.r, game->texture.f.g, game->texture.f.b);
	printf("C -> r: %d, g: %d, b: %d\n", game->texture.c.r, game->texture.c.g, game->texture.c.b);

	printf("-----------------------------------------------------\n\n");
}
