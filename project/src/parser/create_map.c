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

int	assign_map(char **map, char *cub);
void print_map(char **map);

char **create_map(char *cub)
{
	char	**map;
	size_t	size;

	size = get_map_size(cub);
	if (size == 0)
		return (ft_printf("Error\n"), NULL);
	map = (char **) ft_calloc(size, sizeof(char *));
	if (!map)
		return (perror("Error"), NULL);
	if (assign_map(map, cub) < 0)
		return (NULL);
	print_map(map);
	return (NULL);
}

void print_map(char **map)
{
	while (*map)
	{
		ft_printf("%s", *map);
		map++;
	}
}

int	assign_map(char **map, char *cub)
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