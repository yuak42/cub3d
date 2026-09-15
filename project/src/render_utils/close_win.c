/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:29:34 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/12 13:38:36 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_win(t_render *args, int status)
{
	void	*mlx_ptr;

	mlx_ptr = args->window.mlx_ptr;
	if (args->window.mlx_ptr && args->window.win_ptr)
		mlx_destroy_window(args->window.mlx_ptr, args->window.win_ptr);
	if (args->window.mlx_ptr && args->img.img_p)
		mlx_destroy_image(args->window.mlx_ptr, args->img.img_p);
	free_render(args);
	if (mlx_ptr)
		mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	exit(status);
}
