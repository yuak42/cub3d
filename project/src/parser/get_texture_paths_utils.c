/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_paths_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:43:58 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 13:11:43 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	deal_texture(char **splitted, t_game *game);

int assign_texture(t_game *game, char *line)
{
	char	**splitted;
	char	*trimmed;

	trimmed = ft_strtrim(line, "\n");
	if (!line)
		return (perror("Error"), 1);
	splitted = ft_split(trimmed, ' ');
	if (!splitted)
		return (perror("Error"), 1);
	if (deal_texture(splitted, game))
		return (1);
	free(splitted[0]);
	free(splitted);
	free(trimmed);
	return (0);
}

int	deal_texture(char **splitted, t_game *game)
{
	if (!ft_strncmp(splitted[0], "NO", 3))
		game->texture.no = splitted[1];
	else if (!ft_strncmp(splitted[0], "SO", 3))
		game->texture.so = splitted[1];
	else if (!ft_strncmp(splitted[0], "WE", 3))
		game->texture.we = splitted[1];
	else if (!ft_strncmp(splitted[0], "EA", 3))
		game->texture.ea = splitted[1];
	else if (!ft_strncmp(splitted[0], "F", 2))
		assign_color(game, 'f', splitted[1]);
	else if (!ft_strncmp(splitted[0], "C", 2))
		assign_color(game, 'c', splitted[1]);
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
	free_split(splitted);
	free(str);
}

int is_texture_line(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	if (!ft_strncmp(line, "SO ", 3))
		return (1);
	if (!ft_strncmp(line, "WE ", 3))
		return (1);
	if (!ft_strncmp(line, "EA ", 3))
		return (1);
	if (!ft_strncmp(line, "F ", 2))
		return (1);
	if (!ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}
