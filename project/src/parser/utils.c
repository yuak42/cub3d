#include "cub3d.h"

size_t	get_map_size(char **av)
{
	int		fd;
	size_t	size;
	char	*line;

	fd = open(av[1], O_RDONLY);
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