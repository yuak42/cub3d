/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:29:34 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/15 16:55:22 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "data.h"
#include "mlx.h"
#include "render.h"

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
