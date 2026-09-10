/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_raydir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 22:26:32 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/09 21:03:29 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_raydir(t_render *args, double x)
{
	double	camerax;

	camerax = ((2 * x) / args->window.w) - 1;
	args->ray_dirx = args->dir_x + args->plane_x * camerax;
	args->ray_diry = args->dir_y + args->plane_y * camerax;
}
