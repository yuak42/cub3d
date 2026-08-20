/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 10:10:57 by yuak              #+#    #+#             */
/*   Updated: 2026/08/20 13:51:30 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fill(char **grid, int x, int y);

int	flood_fill(char **grid, t_player player)
{
	if (fill(grid, player.x, player.y))
		return (print_error("Error\nMap is not closed\n"), 1);
	return (0);
}

static int	fill(char **grid, int x, int y)
{

	
	if (x < 0 || y < 0 || !grid[y] || !grid[y][x])
		return (1);
	if (grid[y][x] == ' ')
		return (1);
	if (grid[y][x] == '1')
		return (0);
	grid[y][x] = '1';
	// ft_printf("-----------------------------------\nGrid:\n");
	// print_grid(grid);
	if (fill(grid, x + 1, y))
		return (1);
	if (fill(grid, x, y + 1))
		return (1);
	if (fill(grid, x, y - 1))
		return (1);
	if (fill(grid, x - 1, y))
		return (1);
	return (0);
}