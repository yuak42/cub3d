/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:15 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 12:41:24 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*create_game(char *cub)
{
	t_map	*map;
	t_game	*game;

	game = (t_game *) ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	map = create_map(cub);
	if (!map->grid)
		return (NULL);
	game->map = map;
	if (get_texture_paths(cub, game) != 0)
		return (NULL);
	return (game);
}



