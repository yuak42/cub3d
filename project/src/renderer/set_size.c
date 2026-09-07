/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-26 12:45:33 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-26 12:45:33 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void set_draw(t_render *args);
static void set_wallx(t_render *args, t_game *game);
static void	set_tex_x(t_render *args);
static void tex_x_mirror(t_render *args, int texwidth);

void set_wall_size(t_render *args, t_game *game)
{
	if (args->size.side == 0)
		args->size.perpwalldist = args->sidedistx - args->deltadistx;
	else if(args->size.side == 1)
		args->size.perpwalldist = args->sidedisty - args->deltadisty;
	args->size.lineheight = (int)(args->window.h / args->size.perpwalldist);
	//printf("perpwalldist:%f\nlineheight:%d\n", args->size.perpwalldist, args->size.lineheight);
	set_draw(args);
	set_wallx(args, game);
	set_tex_x(args);
}

static void set_draw(t_render *args)
{
	args->size.drawstart = -args->size.lineheight / 2 + args->window.h / 2;
	if (args->size.drawstart < 0)
		args->size.drawstart = 0;
	args->size.drawend = args->size.lineheight / 2 + args->window.h  / 2;
	if (args->size.drawend > args->window.h - 1)
		args->size.drawend = args->window.h - 1;
	//printf("draw_end:%d\ndraw_start:%d\n", args->size.drawend, args->size.drawstart);
}

static void set_wallx(t_render *args, t_game *game)
{
	if (args->size.side == 0)
		args->size.wall_x = game->player.y + args->size.perpwalldist * args->ray_diry;
	else if (args->size.side == 1)
		args->size.wall_x = game->player.x + args->size.perpwalldist * args->ray_dirx;
	args->size.wall_x -= floor(args->size.wall_x);
	//printf("wall_x:%f\n", args->size.wall_x);
}

static void	set_tex_x(t_render *args)
{
	if (args->size.side == 0)
	{
		if (args->ray_dirx > 0)
			args->wall = args->ea;
		else if (args->ray_dirx < 0)
			args->wall = args->we;
	}
	else if (args->size.side == 1)
	{
		if (args->ray_diry > 0)
			args->wall = args->so;
		else if (args->ray_diry < 0)
			args->wall = args->no;
	}
	args->size.tex_x = (int)(args->size.wall_x * args->wall.tex_w);
	tex_x_mirror(args, args->wall.tex_w);
	//printf("tex_x:%d\n", args->size.tex_x);
}

static void tex_x_mirror(t_render *args, int texwidth)
{
	if (args->size.side == 0)
	{
		if (args->ray_dirx < 0)
			args->size.tex_x = texwidth - args->size.tex_x - 1;
	}
	if (args->size.side == 1)
	{
		if (args->ray_diry > 0)
			args->size.tex_x = texwidth - args->size.tex_x - 1;
	}
}
