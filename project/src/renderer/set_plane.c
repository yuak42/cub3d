/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-17 21:36:03 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-17 21:36:03 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_plane(t_game *game, t_Rargs *args)
{
	char dir;

	dir = get_spawn_dir(game);
	if (dir == '0')
		return ;
	args->plane_x = -1 * (game->player.dir_y) * 0.66;
	args->plane_y = game->player.dir_x * 0.66;
}