/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:31:52 by yuak              #+#    #+#             */
/*   Updated: 2026/08/30 16:06:06 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_game *game)
{
	char	**grid;

	grid = get_grid_copy(game->map->grid);
	if (!grid)
		return (1);
	if (flood_fill(grid, game->player))
		return (free_grid(grid), 1);
	free_grid(grid);
	if (!is_starting_position_true(game->map->grid))
		return (1);
	return (0);
}
