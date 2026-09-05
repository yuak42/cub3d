/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-04 21:24:39 by byaprak           #+#    #+#             */
/*   Updated: 2026-09-04 21:24:39 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static void	ft_move(t_render *args, int keycode, t_game *game);

int	key_event(void *args)
{
	t_render	*ag;

	ag = args;
	if (ag->flag == 1)
	{
		if (ag->key_code == 65307)
			close_win(args);
		else if(ag->key_code == 65361 || ag->key_code == 65363)
			ft_ray_move(args, ag->key_code);
	}
	return (0);
}

//static void	ft_move(t_render *args, int keycode, t_game *game)
// {
// 	if (keycode == 65361)
// 		join->args.move_x -= join->win.size * 0.05;
// 	else if (keycode == 65363)
// 		join->args.move_x += join->win.size * 0.05;
// 	else if (keycode == 65362)
// 		join->args.move_y -= join->win.size * 0.05;
// 	else if (keycode == 65364)
// 		join->args.move_y += join->win.size * 0.05;
// 	fractol_render(join);
// }
