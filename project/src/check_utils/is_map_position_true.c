/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_position_true.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:23:03 by yuak              #+#    #+#             */
/*   Updated: 2026/08/30 16:06:21 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	go_end_of_map(int fd);
static int	check_map_position(int fd);

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
			if (check_map_position(fd))
				return (get_next_line(-1), free(line), close(fd),  0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}

static int check_map_position(int fd)
{
	char	*line;

	go_end_of_map(fd); // later read_next_line use if (...)
	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (0);
	if (is_map_line(line))
		print_error("Error\nMap is divided\n");
	else
		print_error_arg("Error\nMap is not at the end: ?\n", line);
	return (free(line), 1);
}

static int go_end_of_map(int fd)
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
	return (0); // later get_next_line will change to read_next_line
}
