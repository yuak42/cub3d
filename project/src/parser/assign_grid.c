/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:35:22 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:38:38 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "check.h"
#include "read_next_line.h"

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
	if (read_next_line(fd, &line))
		return (perror("Error"), close(fd), 1);
	while (line)
	{
		if (deal_line(line, map, &grid))
			return (close(fd), 1);
		if (read_next_line(fd, &line))
			return (perror("Error"), close(fd), 1);
	}
	read_next_line(-1, NULL);
	close(fd);
	return (0);
}

static int	deal_line(char *line, t_map *map, char ***grid)
{
	char	*row;
	int		i;

	i = 0;
	if (is_map_line(line))
	{
		row = (char *) ft_calloc((map->width + 1), sizeof(char));
		if (!row)
			return (1);
		while (line[i] && line[i] != '\n')
		{
			row[i] = line[i];
			i++;
		}
		while (i < (int) map->width)
		{
			row[i] = ' ';
			i++;
		}
		**grid = row;
		(*grid)++;
	}
	free(line);
	return (0);
}
