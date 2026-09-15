/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_raydir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 22:26:32 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/15 16:44:27 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	set_raydir(t_render *args, double x)
{
	double	camerax;

	camerax = ((2 * x) / args->window.w) - 1;
	args->ray_dirx = args->dir_x + args->plane_x * camerax;
	args->ray_diry = args->dir_y + args->plane_y * camerax;
}
