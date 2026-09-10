/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:52:25 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/09 21:01:58 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	put_game(t_render *args)
{
	int	x;
	int	result;

	x = 0;
	while (x < args->window.w)
	{
		get_raycast_arg(args->game, args, x);
		run_dda(args, args->game, x);
		x++;
	}
	result = mlx_put_image_to_window(args->window.mlx_ptr,
			args->window.win_ptr, args->img.img_p, 0, 0);
	return (result);
}
