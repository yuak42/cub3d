/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:40:35 by yuak              #+#    #+#             */
/*   Updated: 2026/09/16 17:39:23 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "check.h"
#include "data.h"
#include "free.h"
#include "read_next_line.h"
#include "parser.h"

int	get_texture_paths(char *cub, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (1000);
	if (read_next_line(fd, &line))
		return (perror("Error"), close(fd), 1);
	while (line)
	{
		if (is_texture_line(line))
		{
			if (assign_texture(game, line))
				return (free_texture(game->texture), free(line), close(fd), 1);
		}
		free(line);
		if (read_next_line(fd, &line))
			return (perror("Error"), close(fd), 1);
	}
	read_next_line(-1, NULL);
	close(fd);
	return (0);
}
