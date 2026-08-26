/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-26 12:45:33 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-26 12:45:33 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void set_draw(t_render *args, t_win *window);
static void set_wallx(t_render *args, t_game *game);

void set_wall_size(t_render *args, t_win *window, t_game *game)
{
	if (args->size.side == 0)
		args->size.perpwalldist = args->sidedistx - args->deltadistx;
	else if(args->size.side == 1)
		args->size.perpwalldist = args->sidedisty - args->deltadisty;
	args->size.lineheight = (int)(window->h / args->size.perpwalldist);
}

static void set_draw(t_render *args, t_win *window)
{
	args->size.drawstart = -args->size.lineheight / 2 + window->h / 2;
	if (args->size.drawstart < 0)
		args->size.drawstart == 0;
	args->size.drawend = args->size.lineheight / 2 + window->h / 2;
	if (args->size.drawend > window->w - 1)
		args->size.drawend == window->h - 1;
}

static void set_wallx(t_render *args, t_game *game)
{
	if (args->size.side == 0)
		args->size.wall_x = game->player.y + args->size.perpwalldist * args->ray_diry;
	if (args->size.side == 1)
		args->size.wall_x = game->player.x + args->size.perpwalldist * args->ray_dirx;
	args->size.wall_x = floor(args->size.wall_x);
}
