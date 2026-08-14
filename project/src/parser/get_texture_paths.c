/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:40:35 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 15:55:05 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_texture_paths(char *cub, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (1000);
	line = get_next_line(fd);
	while (line)
	{
		if (is_texture_line(line))
		{
			if (assign_texture(game, line))
				return (free_texture(game->texture), free(line), close(fd), 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
