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

static int is_out_of_bounds(t_render *args, t_map *map);

void	run_dda(t_render *args, t_map *map)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (args->sidedistx < args->sidedisty)
		{
			args->sidedistx += args->deltadistx;
			args->mapx +=args->stepx;
			side = 0;
		}
		else
		{
			args->sidedisty += args->deltadisty;
			args->mapy +=args->stepy;
			side = 1;
		}
		if (!is_out_of_bounds(args, map))
			break;
		if (map->grid[args->mapy][args->mapx] == '1')
			hit = 1;
	}
	if (hit == 1)
		printf("map_x:%d map_y:%d side:%d\n", args->mapx, args->mapy, side);
}

static int is_out_of_bounds(t_render *args, t_map *map)
{
	if (args->mapx >= 0 && args->mapx < (int) map->width)
	{
		if (args->mapy >= 0 && args->mapy < (int) map->height)
			return (1);
	}
	return (0);
}