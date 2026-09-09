/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 16:33:52 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/09 21:03:09 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_sidedist(t_render *args, t_game *game);
static void	get_stepx(t_render *args);

void	set_map(t_render *args, t_game *game)
{
	args->mapx = (int)(game->player.x);
	args->mapy = (int)(game->player.y);
	if (args->ray_dirx == 0)
		args->deltadistx = 1e30;
	else
		args->deltadistx = fabs(1 / args->ray_dirx);
	if (args->ray_diry == 0)
		args->deltadisty = 1e30;
	else
		args->deltadisty = fabs(1 / args->ray_diry);
	get_stepx(args);
	get_sidedist(args, game);
}

static void	get_sidedist(t_render *args, t_game *game)
{
	if (args->stepx == -1)
		args->sidedistx = (game->player.x - args->mapx) * args->deltadistx;
	else if (args->stepx == 1)
		args->sidedistx = (args->mapx + 1 - game->player.x) * args->deltadistx;
	if (args->stepy == -1)
		args->sidedisty = (game->player.y - args->mapy) * args->deltadisty;
	else if (args->stepy == 1)
		args->sidedisty = (args->mapy + 1 - game->player.y) * args->deltadisty;
}

static void	get_stepx(t_render *args)
{
	if (args->ray_dirx < 0)
		args->stepx = -1;
	else
		args->stepx = 1;
	if (args->ray_diry < 0)
		args->stepy = -1;
	else
		args->stepy = 1;
}
