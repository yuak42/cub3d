/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 01:04:17 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/15 16:24:33 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "render.h"

static int	is_out_of_bounds(t_render *args, t_map *map);
static void	put_texture(t_render *args, t_game *game, int x);

void	run_dda(t_render *args, t_game *game, int x)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (args->sidedistx < args->sidedisty)
		{
			args->sidedistx += args->deltadistx;
			args->mapx += args->stepx;
			args->size.side = 0;
		}
		else
		{
			args->sidedisty += args->deltadisty;
			args->mapy += args->stepy;
			args->size.side = 1;
		}
		if (!is_out_of_bounds(args, game->map))
			break ;
		if (game->map->grid[args->mapy][args->mapx] == '1')
			hit = 1;
	}
	if (hit == 1)
		put_texture(args, game, x);
}

static void	put_texture(t_render *args, t_game *game, int x)
{
	set_wall_size(args, game);
	put_window(args, game, x);
}

static int	is_out_of_bounds(t_render *args, t_map *map)
{
	if (args->mapx >= 0 && args->mapx < (int) map->width)
	{
		if (args->mapy >= 0 && args->mapy < (int) map->height)
			return (1);
	}
	return (0);
}
