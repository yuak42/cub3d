/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:52:25 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/15 16:40:07 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mlx.h"
#include "render.h"

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
