#include "cub3d.h"

size_t	get_map_size(char *cub)
{
	int		fd;
	size_t	size;
	char	*line;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), 0);
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
			size++;
		line = get_next_line(fd);
	}
	return (size);
}

int is_map_line(char *line)
{
	if (ft_strnstr(line, "NO ", 3))
		return (0);
	if (ft_strnstr(line, "SO ", 3))
		return (0);
	if (ft_strnstr(line, "WE ", 3))
		return (0);
	if (ft_strnstr(line, "EA ", 3))
		return (0);
	if (ft_strnstr(line, "F ", 2))
		return (0);
	if (ft_strnstr(line, "C ", 2))
		return (0);
	if (line[0] == '\n')
		return (0);
	return (1);
}

void print_grid(char **grid)
{
	while (*grid)
	{
		ft_printf("%s", *grid);
		grid++;
	}
}

t_map	*init_map(char *cub)
{
	t_map	*map;
	size_t	size;

	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!map)
		return (perror("Error"), NULL);
	size = get_map_size(cub);
	if (size == 0)
		return (ft_printf("Error\n"), NULL);
	map->height = size;
	map->grid = (char **) ft_calloc(size, sizeof(char *));
	if (!map->grid)
		return (perror("Error"), NULL);
	return (map);
}

int	assign_grid(t_map *map, char *cub)
{
	int		fd;
	char	*line;
	char	**grid;

	grid = map->grid;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
		{
			if (map->width < ft_strlen(line))
				map->width = ft_strlen(line);
			*grid = line;
			grid++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	return (0);
}