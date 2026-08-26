/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_position_true.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:23:03 by yuak              #+#    #+#             */
/*   Updated: 2026/08/26 13:24:21 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	go_end_of_map(int fd);

int	is_map_position_true(char *cub)
{
	int		fd;
	char	*line;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1000);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
		{
			printf("The map is starting with line: %s", line);
			if (go_end_of_map(fd))
				return (close(fd), free(line), 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	print_error("Error\nMap position is wrong!");
	return (close(fd), 0);
}

static int	go_end_of_map(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!is_map_line(line))
		{
			printf("This line is not map line: %s", line);
			return (free(line), 1);
		}
		printf("map line: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
