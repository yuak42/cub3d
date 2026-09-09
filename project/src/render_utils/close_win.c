/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:29:34 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/09 21:01:06 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_render *args)
{
	void	*mlx_ptr;

	mlx_ptr = args->window.mlx_ptr;
	mlx_destroy_window(args->window.mlx_ptr, args->window.win_ptr);
	mlx_destroy_image(args->window.mlx_ptr, args->img.img_p);
	free_render(args);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	exit(0);
}
