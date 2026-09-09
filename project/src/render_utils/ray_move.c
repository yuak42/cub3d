/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 21:53:08 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/09 21:00:53 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rot_dir(t_render *args, double rot);
static void	rot_plane(t_render *args, double rot);

void	ray_move(t_render *args)
{
	double	rot;

	if (args->key.left)
		rot = -0.05;
	else if (args->key.right)
		rot = 0.05;
	rot_dir(args, rot);
	rot_plane(args, rot);
	put_game(args);
}

static void	rot_dir(t_render *args, double rot)
{
	double	old_dir;

	old_dir = args->dir_x;
	args->dir_x = args->dir_x * cos(rot) - args->dir_y * sin(rot);
	args->dir_y = old_dir * sin(rot) + args->dir_y * cos(rot);
}

static void	rot_plane(t_render *args, double rot)
{
	double	old_plane;

	old_plane = args->plane_x;
	args->plane_x = args->plane_x * cos(rot) - args->plane_y * sin(rot);
	args->plane_y = old_plane * sin(rot) + args->plane_y * cos(rot);
}
