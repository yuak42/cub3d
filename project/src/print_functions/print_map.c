#include "cub3d.h"


void print_map(t_map *map)
{
	ft_printf("\n-----------------------------------------------------\n");
	ft_printf("The extracted map:\n\n");
	ft_printf("Map width: %d\nMap height: %d\n\n\n", map->width, map->height);
	print_grid(map->grid);
	ft_printf("-----------------------------------------------------\n\n");
}

void print_grid(char **grid)
{
	while (*grid)
	{
		ft_printf("%s\n", *grid);
		grid++;
	}
}
