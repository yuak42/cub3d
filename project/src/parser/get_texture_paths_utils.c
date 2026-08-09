/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_paths_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:43:58 by yuak              #+#    #+#             */
/*   Updated: 2026/08/09 09:40:54 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_texture_paths(t_game *game)
{
	ft_printf("\n\nTexture paths:\n");
	ft_printf("NO -> %s\n", game->texture.no);
	ft_printf("SO -> %s\n", game->texture.so);
	ft_printf("WE -> %s\n", game->texture.we);
	ft_printf("EA -> %s\n", game->texture.ea);
	
	ft_printf("F -> r: %d, g: %d, b: %d\n", game->texture.f.r, game->texture.f.g, game->texture.f.b);
	
	ft_printf("C -> r: %d, g: %d, b: %d\n", game->texture.c.r, game->texture.c.g, game->texture.c.b);
}

int assign_texture(t_game *game, char *line)
{
	char	**splitted;

	line = ft_strtrim(line, "\n"); // error check later
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
		assign_color(game, 'f', splitted[1]);
	else if (ft_strnstr(line, "C ", 2))
		assign_color(game, 'c', splitted[1]);
	free(splitted[0]);
	free(splitted);
	return (0);
}

void	assign_color(t_game *game, char c, char *str)
{
	char **splitted;

	splitted = ft_split(str, ','); // error check		
	if (c == 'f')
	{
		game->texture.f.r = ft_atoi(splitted[0]);
		game->texture.f.g = ft_atoi(splitted[1]);
		game->texture.f.b = ft_atoi(splitted[2]);
	}
	else
	{
		game->texture.c.r = ft_atoi(splitted[0]);
		game->texture.c.g = ft_atoi(splitted[1]);
		game->texture.c.b = ft_atoi(splitted[2]);
	}
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
