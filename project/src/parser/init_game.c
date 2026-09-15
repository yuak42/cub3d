/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:15 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:42:50 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#include "data.h"
#include "free.h"
#include "libft.h"
#include "parser.h"

t_game	*init_game(char *cub)
{
	t_game	*game;

	game = (t_game *) ft_calloc(1, sizeof(t_game));
	if (!game)
		return (perror("Error"), NULL);
	game->map = extract_map(cub);
	if (!game->map)
		return (free(game), NULL);
	if (get_texture_paths(cub, game))
		return (free_map(game->map), free(game), NULL);
	if (get_player_position(game))
		return (free_game(game), NULL);
	return (game);
}
