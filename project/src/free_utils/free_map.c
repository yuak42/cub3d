/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:40:24 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 15:44:47 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	char	**grid;

	grid = map->grid;
	while (*grid)
	{
		free(*grid);
		grid++;
	}
	free(map->grid);
	free(map);
}