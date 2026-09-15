/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 10:10:57 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 09:39:57 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fill(char **grid, int x, int y);
static int	is_filling_char(char c);

int	flood_fill(char **grid)
{
	int	x;
	int	y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (is_filling_char(grid[y][x]))
			{
				if (fill(grid, x, y))
					return (print_error("Error\nMap is not closed\n"), 1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	is_filling_char(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
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
