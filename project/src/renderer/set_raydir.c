/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_raydir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-17 22:26:32 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-17 22:26:32 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_raydir(t_game *game, t_render *args, int width)
{
	int	camerax;

	camerax = ((2 * x) / game->map->width) - 1; // width ekran boyutu olacak. 
	args->ray_dirx = game->player.dir_x + args->plane_x * camerax;
	args->ray_diry = game->player.dir_y + args->plane_y * camerax;

}