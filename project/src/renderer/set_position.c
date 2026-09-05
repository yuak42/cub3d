/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-16 11:22:39 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-16 11:22:39 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_position(t_game *game, t_render *args)
{
	game->player.x += 0.5;
	game->player.y += 0.5;
	args->dir_x = game->player.dir_x;
	args->dir_y = game->player.dir_y;
}

// void	set_position(t_game *game)
// {
// 	char	**grid;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	grid = game->map->grid;
// 	while(grid[i])
// 	{
// 		j = 0;
// 		while(grid[i][j])
// 		{
// 			if (grid[i][j]== 'N' || grid[i][j] == 'S' || grid[i][j]== 'E' || grid[i][j] == 'W')
// 			{
// 				game->player.x = j+ 0.5;
// 				game->player.y = i + 0.5;
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }