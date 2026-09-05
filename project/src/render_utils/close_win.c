/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-04 21:29:34 by byaprak           #+#    #+#             */
/*   Updated: 2026-09-04 21:29:34 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_render *args)
{
	mlx_destroy_window(args->window.mlx_ptr, args->window.win_ptr);
	mlx_destroy_image(args->window.mlx_ptr, args->img.img_p);
	mlx_destroy_display(args->window.mlx_ptr);
	free(args);
	exit(0);
}