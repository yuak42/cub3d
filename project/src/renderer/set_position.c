/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:22:39 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/15 16:44:21 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	set_position(t_game *game, t_render *args)
{
	game->player.x += 0.5;
	game->player.y += 0.5;
	args->dir_x = game->player.dir_x;
	args->dir_y = game->player.dir_y;
}
