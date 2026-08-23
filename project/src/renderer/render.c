/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:12 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 12:13:18 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_game *game)
{
	(void) game;
	t_render *args;
	t_win	*window;

	args = ft_calloc(sizeof(t_render), 1);
	window = ft_calloc(sizeof(t_win), 1);
	ft_printf("Game is being rendered\n");
	// set_dir(game);
	if (!init_window(window))
		return (0);
	set_position(game);
	set_plane(game, args);
	set_raydir(game, args, window->w);
	printf("dir_x:%f\ndir_y:%f\n", game->player.dir_x, game->player.dir_y);
	printf("x:%f\ny:%f\n", game->player.x, game->player.y);
	printf("plane_x:%f\nplane_y:%f\n", args->plane_x, args->plane_y);
	return (0);
}
