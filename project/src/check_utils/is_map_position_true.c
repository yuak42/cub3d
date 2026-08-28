/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_position_true.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:23:03 by yuak              #+#    #+#             */
/*   Updated: 2026/08/28 20:17:53 by yuak             ###   ########.fr       */
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
	get_next_line(-1);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		else if (is_map_line(line))
		{
			if (go_end_of_map(fd))
				return (free(line), close(fd), print_error("Error\nMap position is wrong!"), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}

static int	go_end_of_map(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!is_map_line(line))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (0);
	return (free(line), 1);
}