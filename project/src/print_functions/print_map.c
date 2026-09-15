#include "data.h"
#include <stdio.h>
#include "cub3d.h"


void print_map(t_map *map)
{
	printf("\n-----------------------------------------------------\n");
	printf("The extracted map:\n\n");
	printf("Map width: %ld\nMap height: %ld\n\n\n", map->width, map->height);
	print_grid(map->grid);
	printf("-----------------------------------------------------\n\n");
}

void print_grid(char **grid)
{
	while (*grid)
	{
		printf("%s\n", *grid);
		grid++;
	}
}
