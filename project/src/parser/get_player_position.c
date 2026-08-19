/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 10:15:05 by yuak              #+#    #+#             */
/*   Updated: 2026/08/19 19:24:09 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_starting_position(char c);
static void	assign_player_info(t_game *game, int x, int y);

int	get_player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (int) game->map->height)
	{
		while (x < (int) ft_strlen(game->map->grid[y]))
		{
			if (is_starting_position(game->map->grid[y][x]))
				return (assign_player_info(game, x, y), 0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

static int	is_starting_position(char c)
{
	if (c == '1' || c == '0' || c == ' ')
		return (0);
	return (1);
}

static void	assign_player_info(t_game *game, int x, int y)
{
	game->player.x = (double) x;
	game->player.y = (double) y;
	if (game->map->grid[y][x] == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->map->grid[y][x] == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->map->grid[y][x] == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (game->map->grid[y][x] == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
}
