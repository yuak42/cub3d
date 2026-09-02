/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-23 15:10:20 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-23 15:10:20 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_window(t_render *args)
{
	args->window.mlx_ptr = mlx_init();
	if (!(args->window.mlx_ptr))
	{
		printf("mlx_init error\n");
		return (0);
	} 
	args->window.h = 720;
	args->window.w = 1280;
	args->window.win_ptr = mlx_new_window(args->window.mlx_ptr, args->window.w, args->window.h, "CUB3D");
 	if (!(args->window.win_ptr))
    {
        printf("mlx_new_window error\n");
        return (0);
    }
	return (1);
}
