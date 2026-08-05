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

char **create_map(char **ar)
{
	int		fd;
	char	**map;
	char	*line;

	fd = open(ar[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), NULL);

	map = (char **) malloc(sizeof(char *));
	map[0] = NULL;
	
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
			ft_printf("Map line\n");
		else
			ft_printf("Not map line\n");
		line = get_next_line(fd);
	}

	return (map);
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