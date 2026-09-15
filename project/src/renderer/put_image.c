/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:54:53 by byaprak           #+#    #+#             */
/*   Updated: 2026/09/12 20:19:33 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color(t_render *args, int tex_x, int tex_y);
static void	image_piksel_put(t_render *args, int color, int tex_x, int tex_y);
static void	set_texture(t_render *args, int x, int y, double tex_pos);
static void	set_rgb(t_render *args, t_game *game, int x, int y);

int	put_window(t_render *args, t_game *game, int x)
{
	double	step;
	double	tex_pos;
	int		y;

	y = 0;
	step = 1.0 * args->wall.tex_h / args->size.lineheight;
	tex_pos = (args->size.drawstart - args->window.h / 2
			+ args->size.lineheight / 2) * step;
	while (y < args->window.h)
	{
		if (y < args->size.drawstart)
			set_rgb(args, game, x, y);
		else if (y >= args->size.drawstart && y < args->size.drawend)
		{
			set_texture(args, x, y, tex_pos);
			tex_pos += step;
		}
		else
			set_rgb(args, game, x, y);
		y++;
	}
	return (1);
}

static void	set_texture(t_render *args, int x, int y, double tex_pos)
{
	int	color;
	int	texy;

	texy = (int)tex_pos % (args->wall.tex_h -1);
	color = get_color(args, args->size.tex_x, texy);
	image_piksel_put(args, color, x, y);
}

static void	set_rgb(t_render *args, t_game *game, int x, int y)
{
	int	color;

	if (y < args->size.drawstart)
	{
		color = game->texture.c.r << 16
			| game->texture.c.g << 8 | game->texture.c.b;
	}
	if (y > args->size.drawstart)
	{
		color = game->texture.f.r << 16
			| game->texture.f.g << 8 | game->texture.f.b;
	}
	image_piksel_put(args, color, x, y);
}

static void	image_piksel_put(t_render *args, int color, int tex_x, int tex_y)
{
	char	*addr;

	addr = args->img.img_pixel;
	addr += (tex_y * args->img.len) + tex_x * (args->img.bpp / 8);
	*((int *)(addr)) = color;
}

static int	get_color(t_render *args, int tex_x, int tex_y)
{
	char	*color;
	int		color_int;

	if (!args->wall.w_pixel)
		return (0xFF0000);
	if (tex_y < 0 || tex_y >= args->wall.tex_h)
		tex_y = tex_y & (args->wall.tex_h - 1);
	if (tex_x < 0 || tex_x >= args->wall.tex_w)
		tex_x = tex_x & (args->wall.tex_w - 1);
	color = args->wall.w_pixel + (tex_y * args->wall.len)
		+ tex_x * (args->wall.bpp / 8);
	color_int = ((int *)color)[0];
	return (color_int);
}
