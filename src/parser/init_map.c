/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 11:56:45 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:37:08 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "check.h"
#include "data.h"
#include "libft.h"
#include "read_next_line.h"

static size_t	get_map_height(char *cub);
static size_t	get_map_width(char *cub);

t_map	*init_map(char *cub)
{
	t_map	*map;

	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!map)
		return (perror("Error"), NULL);
	map->height = get_map_height(cub);
	map->width = get_map_width(cub);
	if (!map->height || !map->width)
		return (NULL);
	map->grid = (char **) ft_calloc(map->height + 1, sizeof(char *));
	if (!map->grid)
		return (perror("Error"), NULL);
	return (map);
}

static size_t	get_map_height(char *cub)
{
	int		fd;
	size_t	size;
	char	*line;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), 0);
	size = 0;
	if (read_next_line(fd, &line))
		return (perror("Error"), close(fd), 1);
	while (line)
	{
		if (is_map_line(line))
			size++;
		free(line);
		if (read_next_line(fd, &line))
			return (perror("Error"), close(fd), 1);
	}
	close(fd);
	return (read_next_line(-1, NULL), size);
}

static size_t	get_map_width(char *cub)
{
	int		fd;
	char	*line;
	size_t	size;

	size = 0;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (0);
	if (read_next_line(fd, &line))
		return (perror("Error"), close(fd), 1);
	while (line)
	{
		if (is_map_line(line))
		{
			if (size < ft_strlen(line))
				size = ft_strlen(line);
		}
		free(line);
		if (read_next_line(fd, &line))
			return (perror("Error"), close(fd), 1);
	}
	return (read_next_line(-1, NULL), size - 1);
}
