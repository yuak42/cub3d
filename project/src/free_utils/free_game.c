/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 08:24:00 by yuak              #+#    #+#             */
/*   Updated: 2026/08/13 09:06:12 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map_grid(char **grid);
static void	free_texture(t_texture texture);

void	free_game(t_game *game)
{
	free_map_grid(game->map->grid);
	free_texture(game->texture);
	free(game->map);
	free(game);
}

static void	free_map_grid(char **grid)
{
	char	**temp;

	temp = grid;
	while (*grid)
	{
		free(*grid);
		grid++;
	}
	free(temp);
}

static void	free_texture(t_texture texture)
{
	free(texture.no);
	free(texture.so);
	free(texture.we);
	free(texture.ea);
}