/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 21:39:27 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/15 16:46:42 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

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
