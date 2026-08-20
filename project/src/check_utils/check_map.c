/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 10:31:52 by yuak              #+#    #+#             */
/*   Updated: 2026/08/20 10:09:25 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_game *game)
{
	char	**grid;

	grid = get_grid_copy(game->map->grid);
	if (!grid)
		return (1);
	ft_printf("--------------------------\n-----------------------------\nChecking\n");
	print_grid(grid);
	// if (flood_fill(grid))
	// 	return (1);
	return (0);
}



int	flood_fill(char **grid)
{
	(void) grid;
	return (0);
}