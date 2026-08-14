/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 11:56:45 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 12:45:37 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		free(line);
		line = get_next_line(fd); // should we check get_next_line malloc errors with strerror?
	}
	close(fd);
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

t_map	*init_map(char *cub)
{
	t_map	*map;
	size_t	size;

	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!map)
		return (perror("Error"), NULL);
	size = get_map_size(cub);
	if (size == 0)
		return (NULL);
	map->height = size;
	map->grid = (char **) ft_calloc(size + 1, sizeof(char *));
	if (!map->grid)
		return (perror("Error"), NULL);
	return (map);
}

static int	deal_line(char *line, t_map *map, char ***grid);

int	assign_grid(t_map *map, char *cub)
{
	int		fd;
	char	*line;
	char	**grid;

	grid = map->grid;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (1000);
	line = get_next_line(fd);
	while (line)
	{
		if (deal_line(line, map, &grid))
			return (close(fd), 1);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

static int	deal_line(char *line, t_map *map, char ***grid)
{
	char	*row;

	if (is_map_line(line))
	{
		row = ft_strtrim(line, "\n");
		free(line);
		if (!row)
			return (1);
		if (map->width < ft_strlen(row))
			map->width = ft_strlen(row);
		**grid = row;
		(*grid)++;
	}
	else
		free(line);
	return (0);
}