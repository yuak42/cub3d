/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_position_true.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:23:03 by yuak              #+#    #+#             */
/*   Updated: 2026/09/16 16:53:21 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "check.h"
#include "read_next_line.h"

static int	go_end_of_map(int fd);
static int	check_map_position(int fd);

int	is_map_position_true(char *cub)
{
	int		fd;
	char	*line;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), 1000);
	if (read_next_line(fd, &line))
		return (close(fd), perror("Error"), 0);
	while (line)
	{
		if (is_map_line(line))
		{
			if (check_map_position(fd))
				return (free(line), close(fd), read_next_line(-1, NULL), 0);
		}
		free(line);
		if (read_next_line(fd, &line))
			return (close(fd), perror("Error"), read_next_line(-1, NULL), 0);
	}
	return (close(fd), read_next_line(-1, NULL), 1);
}

static int	check_map_position(int fd)
{
	char	*line;

	if (go_end_of_map(fd))
		return (1);
	if (read_next_line(fd, &line))
		return (perror("Error"), 1);
	while (line && line[0] == '\n')
	{
		free(line);
		if (read_next_line(fd, &line))
			return (perror("Error"), 1);
	}
	if (!line)
		return (0);
	if (is_map_line(line))
		print_error("Error\nMap is divided\n");
	else
		print_error_arg("Error\nMap is not at the end: ?\n", line);
	return (free(line), 1);
}

static int	go_end_of_map(int fd)
{
	char	*line;

	if (read_next_line(fd, &line))
		return (perror("Error"), 1);
	while (line)
	{
		if (!is_map_line(line))
			break ;
		free(line);
		if (read_next_line(fd, &line))
			return (perror("Error"), 1);
	}
	free(line);
	return (0);
}
