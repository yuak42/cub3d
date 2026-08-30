/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_starting_position_true.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:22:29 by yuak              #+#    #+#             */
/*   Updated: 2026/08/30 16:15:37 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_starting_position_char(char c);
static int	get_return(int num);

int	is_starting_position_true(char **grid)
{
	int	x;
	int	y;
	int	num;

	y = 0;
	num = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (is_starting_position_char(grid[y][x]))
				num++;
			x++;
		}
		y++;
	}
	return (get_return(num));
}

static int	is_starting_position_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static int	get_return(int num)
{
	if (num == 1)
		return (1);
	if (num == 0)
		print_error("Error\nThere is no starting position on map\n");
	else if (num > 1)
		print_error("Error\nThere are more than 1 starting position on map\n");
	return (0);
}