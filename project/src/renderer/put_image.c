/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com.tr>  #+#  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-08-30 21:54:53 by byaprak           #+#    #+#             */
/*   Updated: 2026-08-30 21:54:53 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static  int	get_color(t_render *args, int tex_x, int tex_y);
static void	image_piksel_put(t_render *args, int color, int tex_x, int tex_y);

int put_window(t_render *args, t_game *game, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		texy;
	int		color;

	y = 0;
	//args->wall.w_pixel = mlx_get_data_addr(args->wall.w_p, &args->wall.bpp, &args->wall.len, &args->wall.end);
	step = 1.0 * args->wall.tex_h / args->size.lineheight;
	tex_pos = (args->size.drawstart - args->window.h / 2 + args->size.lineheight / 2) * step;
	while(y < args->window.h)
	{
		if (y < args->size.drawstart)
		{
			color = game->texture.f.r << 16 | game->texture.f.g << 8 | game->texture.f.b;
			image_piksel_put(args, color, x, y);
		}
		else if (y >= args->size.drawstart && y < args->size.drawend)
		{
			texy = (int)tex_pos & (args->wall.tex_h -1);
			tex_pos += step;
			color = get_color(args, args->size.tex_x, texy);
			image_piksel_put(args, color, x, y);
		}
		else
		{
			color = game->texture.c.r << 16 | game->texture.c.g << 8 | game->texture.c.b;
			image_piksel_put(args, color, x, y);
		}
		y++;
	}
	return (1);
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
	{
        tex_x = tex_x & (args->wall.tex_w - 1);
	}
	color = args->wall.w_pixel + (tex_y * args->wall.len) + tex_x * (args->wall.bpp / 8);
	color_int = ((int *)color)[0];
	return (color_int);
}
