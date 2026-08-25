/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raycast_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-24 19:28:45 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-24 19:28:45 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_raycast_arg(t_game *game, t_render *args, t_win *window)
{
	set_position(game);
	set_plane(game, args);
	set_raydir(game, args, window->w, 26);
	set_map(args, game);
}