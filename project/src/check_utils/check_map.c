/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:31:52 by yuak              #+#    #+#             */
/*   Updated: 2026/08/20 13:49:21 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_game *game)
{
	char	**grid;

	grid = get_grid_copy(game->map->grid);
	if (!grid)
		return (1);
	// ft_printf("--------------------------\n-----------------------------\nChecking\n");
	// print_grid(grid);
	if (flood_fill(grid, game->player))
		return (free_grid(grid), 1);
	free_grid(grid);
	return (0);
}
