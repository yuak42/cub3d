/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 15:25:25 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/12 12:50:01 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
