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
// Update header

#include "cub3d.h"

int is_map_line(char *line);
size_t	get_map_size(char **av);

char **create_map(char **av)
{
	char	**map;
	size_t	size;

	size = get_map_size(av);
	if (size == 0)
		return (ft_printf("Error\n"), NULL);
	map = (char **) ft_calloc(size, sizeof(char *));
	if (!map)
		return (perror("Error"), NULL);
	

	return (NULL);
}

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