/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:24:39 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/12 13:41:26 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_event(void *args)
{
	t_render	*ag;
	int			moved;

	ag = args;
	moved = 0;
	if (ag->key_code == 65307)
		close_win(args, 1);
	if (ag->key.w || ag->key.s || ag->key.a || ag->key.d)
	{
		move_pose(args);
		moved = 1;
	}
	if (ag->key.left || ag->key.right)
	{
		ray_move(args);
		moved = 1;
	}
	if (moved)
		put_game(ag);
	return (0);
}
