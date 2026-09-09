/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-16 11:22:39 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-16 11:22:39 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_position(t_game *game, t_render *args)
{
	game->player.x += 0.5;
	game->player.y += 0.5;
	args->dir_x = game->player.dir_x;
	args->dir_y = game->player.dir_y;
}
