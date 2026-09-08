/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-04 21:24:39 by byaprak           #+#    #+#             */
/*   Updated: 2026-09-04 21:24:39 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_event(void *args)
{
	t_render	*ag;
	int			keycode;

	ag = args;
	keycode = ag->key_code;
	if (ag->flag == 1)
	{
		if (keycode == 65307)
			close_win(args);
		else if (keycode == 65361 || keycode == 65363)
			ray_move(args, ag->key_code);
		else if (keycode == 119 || keycode == 97
			|| keycode == 115 || keycode == 100)
			move_pose(args);
	}
	return (0);
}
