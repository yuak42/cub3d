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

void	run_dda(t_render *args, t_game *game)
{
	int	hit;

	hit = 0;
	//printf("DDA Başlıyor - Işın yönü Y: %f, Başlangıç mapY: %d, stepY: %d\n", args->ray_diry, args->mapy, args->stepy);
	while (hit == 0)
	{
		if (args->sidedistx < args->sidedisty)
		{
			args->sidedistx += args->deltadistx;
			args->mapx +=args->stepx;
			args->size.side = 0;
		}
		else
		{
			args->sidedisty += args->deltadisty;
			args->mapy +=args->stepy;
			args->size.side = 1;
		}
		//printf("  DDA Adımı - mapX: %d, mapY: %d\n", args->mapx, args->mapy);
		if (!is_out_of_bounds(args, game->map))
			break;
		if (game->map->grid[args->mapy][args->mapx] == '1')
			hit = 1;
	}
	if (hit == 1)
		set_wall_size(args, game);
	// 	printf("map_x:%d map_y:%d side:%d\n", args->mapx, args->mapy, side);
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