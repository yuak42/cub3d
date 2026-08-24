/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-24 16:33:52 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-24 16:33:52 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_map(t_render *args, t_game *game)
{
	args->mapx = (int) (game->player.x);
	args->mapy = (int) (game->player.y);
	if (args->ray_dirx == 0)
		args->deltadistx = 1e30;
	else
		args->deltadistx = 1 / args->ray_dirx;
	if (args->ray_diry == 0)
		args->deltadisty = 1e30;
	else
		args->deltadisty = 1 / args->ray_diry;
	if (args->ray_dirx < 0)
		args->stepx = -1;
	else
		args->stepx = 1;
	if (args->ray_diry < 0)
		args->stepy = -1;
	else
		args->stepy = 1;
}
