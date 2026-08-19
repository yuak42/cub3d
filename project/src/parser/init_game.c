/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:15 by yuak              #+#    #+#             */
/*   Updated: 2026/08/19 10:07:40 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_player_position(t_game *game);

t_game	*init_game(char *cub)
{
	t_game	*game;

	game = (t_game *) ft_calloc(1, sizeof(t_game));
	if (!game)
		return (perror("Error"), NULL);
	game->map = extract_map(cub);
	if (!game->map)
		return (free(game), NULL);
	if (get_texture_paths(cub, game))
		return (free_map(game->map), free(game), NULL);
	if (get_player_position(game))
		return (free_game(game), NULL);
	return (game);
}

int		is_starting_position(char c);
void	assign_player_info(t_game *game, double x, double y);

int	get_player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < (int) game->map->width)
	{
		while (y < (int) game->map->height)
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

int	is_starting_position(char c)
{
	if (c == '1' || c == '0' || c == ' ')
		return (0);
	return (1);
}

void	assign_player_info(t_game *game, double x, double y)
{
	game->player.x = x;
	game->player.y = y;
	if (game->map->grid[(int)y][(int)x] == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->map->grid[(int)y][(int)x] == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->map->grid[(int)y][(int)x] == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (game->map->grid[(int)y][(int)x] == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
}