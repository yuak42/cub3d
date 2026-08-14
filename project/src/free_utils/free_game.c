/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 08:24:00 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 15:45:15 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_texture(t_texture texture);

void	free_game(t_game *game)
{
	free_texture(game->texture);
	free_map(game->map);
	free(game);
}

static void	free_texture(t_texture texture)
{
	free(texture.no);
	free(texture.so);
	free(texture.we);
	free(texture.ea);
}