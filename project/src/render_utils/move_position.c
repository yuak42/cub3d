/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-09-06 13:16:54 by byaprak           #+#    #+#             */
/*   Updated: 2026-09-06 13:16:54 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void up_move(t_render *args);
static void down_move(t_render *args);
static void left_move(t_render *args);
static void right_move(t_render *args);

void	move_pose(t_render *args)
{

	if (args->key_code == 119)
		up_move(args);
	else if (args->key_code == 115)
		down_move(args);
	else if (args->key_code == 97)
		left_move(args);
	else if (args->key_code == 100)
		right_move(args);
	put_game(args);
}

static void up_move(t_render *args)
{
	double	x;
	double	y;
	double	new_x;
	double	new_y;

	new_x = args->game->player.x;
	new_y = args->game->player.y;
	x = args->game->player.x + args->dir_x * 0.05;
	y = args->game->player.y + args->dir_y * 0.05;
	if (is_walkable(args->game, x, args->game->player.y))
		new_x = x;
	if (is_walkable(args->game, args->game->player.x, y))
		new_y = y;
	args->game->player.x = new_x;
	args->game->player.y = new_y;
}

static void down_move(t_render *args)
{
	double	x;
	double	y;
	double	new_x;
	double	new_y;

	new_x = args->game->player.x;
	new_y = args->game->player.y;
	x = args->game->player.x - args->dir_x * 0.05;
	y = args->game->player.y - args->dir_y * 0.05;
	if (is_walkable(args->game, x, args->game->player.y))
		new_x = x;
	if (is_walkable(args->game, args->game->player.x, y))
		new_y = y;
	args->game->player.x = new_x;
	args->game->player.y = new_y;
}

static void left_move(t_render *args)
{
	double	x;
	double	y;
	double	new_x;
	double	new_y;

	new_x = args->game->player.x;
	new_y = args->game->player.y;
	x = args->game->player.x - args->plane_x * 0.05;
	y = args->game->player.y - args->plane_y * 0.05;
	if (is_walkable(args->game, x, args->game->player.y))
		new_x = x;
	if (is_walkable(args->game, args->game->player.x, y))
		new_y = y;
	args->game->player.x = new_x;
	args->game->player.y = new_y;
}

static void right_move(t_render *args)
{
	double	x;
	double	y;
	double	new_x;
	double	new_y;

	new_x = args->game->player.x;
	new_y = args->game->player.y;
	x = args->game->player.x + args->plane_x * 0.05;
	y = args->game->player.y + args->plane_y * 0.05;
	if (is_walkable(args->game, x, args->game->player.y))
		new_x = x;
	if (is_walkable(args->game, args->game->player.x, y))
		new_y = y;
	args->game->player.x = new_x;
	args->game->player.y = new_y;
}

