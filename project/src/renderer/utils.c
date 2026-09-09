/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-17 21:39:27 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-17 21:39:27 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_spawn_dir(t_game *game)
{
	char	**grid;
	char	*row;

	grid = game->map->grid;
	while (*grid)
	{
		row = *grid;
		while (*row)
		{
			if (*row == 'N' || *row == 'S' || *row == 'E' || *row == 'W')
				return (*row);
			row++;
		}
		grid++;
	}
	return ('0');
}
