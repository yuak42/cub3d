/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:45:12 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/15 16:56:11 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	key_press(int key_code, void *args)
{
	t_render	*ag;

	ag = args;
	ag->key_code = key_code;
	if (key_code == 119)
		ag->key.w = 1;
	else if (key_code == 115)
		ag->key.s = 1;
	else if (key_code == 97)
		ag->key.a = 1;
	else if (key_code == 100)
		ag->key.d = 1;
	else if (key_code == 65361)
		ag->key.left = 1;
	else if (key_code == 65363)
		ag->key.right = 1;
	return (0);
}

int	key_release(int key_code, void *args)
{
	t_render	*ag;

	ag = args;
	if (key_code == 119)
		ag->key.w = 0;
	else if (key_code == 115)
		ag->key.s = 0;
	else if (key_code == 97)
		ag->key.a = 0;
	else if (key_code == 100)
		ag->key.d = 0;
	else if (key_code == 65361)
		ag->key.left = 0;
	else if (key_code == 65363)
		ag->key.right = 0;
	return (0);
}

int	is_walkable(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= (int)game->map->width)
		return (0);
	if (map_y < 0 || map_y >= (int)game->map->height)
		return (0);
	if (game->map->grid[map_y][map_x] == '1')
		return (0);
	return (1);
}
