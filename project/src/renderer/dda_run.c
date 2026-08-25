/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-25 01:04:17 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-25 01:04:17 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_dda(t_render *args, t_map *map)
{
	int	hit;
	int	side;

	hit = 1;
	while (hit == 0)
	{
		if (args->sidedistx < args->sidedisty)
		{
			args->sidedistx += args->deltadisty;
			args->mapx +=args->stepx;
			side = 0;
		}
		else
		{
			args->sidedisty += args->deltadistx;
			args->mapy +=args->stepy;
			side = 1;
		}
		if (map->grid[args->mapx][args->mapy] == '1')
			hit = 1;
	}
	printf("map_x:%d\nmap_y:%dside:%d\n", args->mapx, args->mapy, side);
}