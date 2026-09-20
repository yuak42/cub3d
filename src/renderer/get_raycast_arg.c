/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raycast_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:28:45 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/15 16:27:12 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "render.h"

void	get_raycast_arg(t_game *game, t_render *args, int x)
{
	set_plane(game, args);
	set_raydir(args, x);
	set_map(args, game);
}
