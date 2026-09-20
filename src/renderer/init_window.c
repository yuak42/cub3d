/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 15:10:20 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/20 15:21:53 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "data.h"
#include "mlx.h"

int	init_window(t_render *args)
{
	args->window.mlx_ptr = mlx_init();
	if (!(args->window.mlx_ptr))
		return (print_error("Error\nmlx_init error\n"), 0);
	args->window.h = 720;
	args->window.w = 1280;
	args->window.win_ptr = mlx_new_window(args->window.mlx_ptr,
			args->window.w, args->window.h, "CUB3D");
	if (!(args->window.win_ptr))
		return (print_error("Error\nmlx_new_window error\n"), 0);
	return (1);
}
