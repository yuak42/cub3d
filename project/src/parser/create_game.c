/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:15 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 12:27:41 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int get_texture_paths(char *cub, t_game *game);


t_game	*create_game(char *cub)
{
	t_map	*map;
	t_game	*game;

	game = (t_game *) ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	map = create_map(cub);
	if (!map->grid)
		return (NULL);
	if (get_texture_paths(cub, game) != 0)
		return (NULL);
	game->map = map;
	return (game);
}

int is_texture_line(char *line);

int get_texture_paths(char *cub, t_game *game)
{
	(void) game;
	char	*line;
	int		fd;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_texture_line(line))
			ft_printf("texture line found -> %s",line);
		line = get_next_line(fd);
	}

	return (0);
}

int is_texture_line(char *line)
{
	if (ft_strnstr(line, "NO ", 3))
		return (1);
	if (ft_strnstr(line, "SO ", 3))
		return (1);
	if (ft_strnstr(line, "WE ", 3))
		return (1);
	if (ft_strnstr(line, "EA ", 3))
		return (1);
	if (ft_strnstr(line, "F ", 2))
		return (1);
	if (ft_strnstr(line, "C ", 2))
		return (1);
	return (0);
}