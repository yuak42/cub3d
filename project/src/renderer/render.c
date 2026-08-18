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
	t_Rargs *args;

	args = malloc(sizeof(t_Rargs));
	ft_printf("Game is being rendered\n");
	set_dir(game);
	set_position(game);
	set_plane(game, args);
	printf("dir_x:%f\ndir_y:%f\n", game->player.dir_x, game->player.dir_y);
	printf("x:%f\ny:%f\n", game->player.x, game->player.y);
	printf("plane_x:%f\nplane_y:%f\n", args->plane_x, args->plane_y);
	return (0);
}
