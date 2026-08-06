/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:40:35 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 12:48:09 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_texture_paths(char *cub, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_texture_line(line))
			assign_texture(game, line);
		free(line);
		line = get_next_line(fd);
	}
	print_texture_paths(game);
	return (0);
}
