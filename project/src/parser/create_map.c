/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:15 by yuak              #+#    #+#             */
/*   Updated: 2026/06/27 22:29:25 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		assign_grid(char **map, char *cub);
t_map	*init_map(char *cub);

t_map *create_map(char *cub)
{
	t_map	*map;

	map = init_map(cub);
	if (!map)
		return (NULL);
	if (assign_grid(map->grid, cub) < 0)
		return (NULL);
	ft_printf("Map was extracted successfully\n");
	print_grid(map->grid);
	return (map);
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
	map->grid = (char **) ft_calloc(size, sizeof(char *));
	if (!map->grid)
		return (perror("Error"), NULL);
	return (map);
}

int	assign_grid(char **map, char *cub)
{
	int		fd;
	char	*line;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
		{
			*map = line;
			map++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	return (0);
}