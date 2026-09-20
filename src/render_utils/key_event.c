/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:24:39 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/19 15:57:29 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "render.h"

int	key_event(void *args)
{
	t_render	*ag;
	int			moved;

	ag = args;
	moved = 0;
	if (ag->key_code == KEY_ESC)
		close_win(args, 0);
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
