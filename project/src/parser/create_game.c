/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:15 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 12:39:17 by yuak             ###   ########.fr       */
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
	game->map = map;
	if (get_texture_paths(cub, game) != 0)
		return (NULL);
	return (game);
}

int is_texture_line(char *line);
int assign_texture(t_game *game, char *line);

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
	ft_printf("Texture paths:\n");
	ft_printf("NO -> %s\n", game->texture.no);
	ft_printf("SO -> %s\n", game->texture.so);
	ft_printf("WE -> %s\n", game->texture.we);
	ft_printf("EA -> %s\n", game->texture.ea);
	ft_printf("F -> %s\n", game->texture.f);
	ft_printf("C -> %s\n", game->texture.c);

	return (0);
}

int assign_texture(t_game *game, char *line)
{
	char **splitted;

	splitted = ft_split(line, ' ');
	if (!splitted)
		return (perror("Error"), 1);

	if (ft_strnstr(line, "NO ", 3))
		game->texture.no = splitted[1];
	else if (ft_strnstr(line, "SO ", 3))
		game->texture.so = splitted[1];
	else if (ft_strnstr(line, "WE ", 3))
		game->texture.we = splitted[1];
	else if (ft_strnstr(line, "EA ", 3))
		game->texture.ea = splitted[1];
	else if (ft_strnstr(line, "F ", 2))
		game->texture.f = splitted[1];
	else if (ft_strnstr(line, "C ", 2))
		game->texture.c = splitted[1];
	free(splitted[0]);
	free(splitted);
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