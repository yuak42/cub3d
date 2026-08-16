/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-16 00:35:40 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-16 00:35:40 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char get_spawn(t_game *game);

void	set_dir(t_game *game)
{
	char dir;

	dir = get_spawn(game);
	if (dir == '0')
		return ;
	if (dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
	}
	if (dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;	
	}
	if (dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;	
	}
	if (dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;	
	}
}

static char get_spawn(t_game *game)
{
	char	**grid;
	char	*row;

	grid = game->map->grid;
	while(*grid)
	{
		row = *grid;
		while(*row)
		{
			if (*row== 'N' || *row == 'S' || *row == 'E' || *row == 'W')
				return (*row);
			row++;
		}
		grid++;
	}
	return '0';
}


