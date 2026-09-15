/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 15:25:25 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/15 16:55:51 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "free.h"
#include "render.h"
#include "mlx.h"

void	free_render(t_render *args)
{
	if (args->so.w_p)
		mlx_destroy_image(args->window.mlx_ptr, args->so.w_p);
	if (args->no.w_p)
		mlx_destroy_image(args->window.mlx_ptr, args->no.w_p);
	if (args->we.w_p)
		mlx_destroy_image(args->window.mlx_ptr, args->we.w_p);
	if (args->ea.w_p)
		mlx_destroy_image(args->window.mlx_ptr, args->ea.w_p);
	free_game(args->game);
	free(args);
}
