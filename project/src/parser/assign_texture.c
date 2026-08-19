/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:43:58 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 16:03:48 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	deal_texture(char **splitted, t_game *game);
static int	assign_color(t_game *game, char c, char *str);

int assign_texture(t_game *game, char *line)
{
	char	**splitted;
	char	*trimmed;

	trimmed = ft_strtrim(line, "\n");
	if (!trimmed)
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

static int	deal_texture(char **splitted, t_game *game)
{
	if (!ft_strncmp(splitted[0], "NO", 3))
		game->texture.no = splitted[1];
	else if (!ft_strncmp(splitted[0], "SO", 3))
		game->texture.so = splitted[1];
	else if (!ft_strncmp(splitted[0], "WE", 3))
		game->texture.we = splitted[1];
	else if (!ft_strncmp(splitted[0], "EA", 3))
		game->texture.ea = splitted[1];
	else
	{
		if (!ft_strncmp(splitted[0], "F", 2))
		{
			if (assign_color(game, 'f', splitted[1]))
				return (1);
		}
		else if (!ft_strncmp(splitted[0], "C", 2))
		{
			if (assign_color(game, 'c', splitted[1]))
				return (1);
		}
	}
	return (0);
}

static int	assign_color(t_game *game, char c, char *str)
{
	char **splitted;

	splitted = ft_split(str, ',');
	free(str);
	if (!splitted)
		return (perror("Error"), 1001);	
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
	return (0);
}
