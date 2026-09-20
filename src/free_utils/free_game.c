/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 08:24:00 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:47:49 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "data.h"
#include "free.h"
#include "read_next_line.h"

void	free_game(t_game *game)
{
	free_texture(game->texture);
	free_map(game->map);
	free(game);
	read_next_line(-1, NULL);
}
