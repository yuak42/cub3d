/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:12 by yuak              #+#    #+#             */
/*   Updated: 2026/09/19 16:17:21 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"
#include "mlx.h"
#include "render.h"

static int	get_img(t_render *args);
static int	win_invisible(void *args);
static int	get_wall(t_render *args, t_game *game);
static void	init_mlx(t_render *args);

int	render(t_game *game)
{
	t_render	*args;

	args = ft_calloc(sizeof(t_render), 1);
	if (!args)
		return (0);
	args->game = game;
	init_mlx(args);
	if (!put_game(args))
		close_win(args, 1);
	mlx_hook(args->window.win_ptr, 12, 1L << 15,
		(int (*)())(void *)win_invisible, args);
	mlx_hook(args->window.win_ptr, 17, 0,
		(int (*)())(void *)mouse_event, args);
	mlx_hook(args->window.win_ptr, 2, 1L << 0,
		(int (*)())(void *)key_press, args);
	mlx_hook(args->window.win_ptr, 3, 1L << 1,
		(int (*)())(void *)key_release, args);
	mlx_loop_hook(args->window.mlx_ptr, (int (*)())(void *)key_event, args);
	mlx_loop(args->window.mlx_ptr);
	return (1);
}

static int	get_img(t_render *args)
{
	args->img.img_p = mlx_new_image(args->window.mlx_ptr,
			args->window.w, args->window.h);
	if (!(args->img.img_p))
	{
		ft_putstr_fd("mlx_new_image error\n", 2);
		return (0);
	}
	args->img.img_pixel = mlx_get_data_addr(args->img.img_p,
			&args->img.bpp, &args->img.len, &args->img.end);
	if (!(args->img.img_pixel))
	{
		ft_putstr_fd("mlx_get_data_addr error\n", 2);
		return (0);
	}
	return (1);
}

static int	win_invisible(void *args)
{
	t_render	*ag;

	ag = (t_render *)args;
	mlx_put_image_to_window(ag->window.mlx_ptr,
		ag->window.win_ptr, ag->img.img_p, 0, 0);
	return (0);
}

static int	get_wall(t_render *args, t_game *game)
{
	args->no.w_p = mlx_xpm_file_to_image(args->window.mlx_ptr, game->texture.no,
			&args->no.tex_w, &args->no.tex_h);
	args->so.w_p = mlx_xpm_file_to_image(args->window.mlx_ptr, game->texture.so,
			&args->so.tex_w, &args->so.tex_h);
	args->ea.w_p = mlx_xpm_file_to_image(args->window.mlx_ptr, game->texture.ea,
			&args->ea.tex_w, &args->ea.tex_h);
	args->we.w_p = mlx_xpm_file_to_image(args->window.mlx_ptr, game->texture.we,
			&args->we.tex_w, &args->we.tex_h);
	if (!args->no.w_p || !args->so.w_p || !args->ea.w_p || !args->we.w_p)
	{
		ft_putstr_fd("mlx_xpm_file_to_image error\n", 2);
		return (0);
	}
	args->no.w_pixel = mlx_get_data_addr(args->no.w_p,
			&args->no.bpp, &args->no.len, &args->no.end);
	args->so.w_pixel = mlx_get_data_addr(args->so.w_p,
			&args->so.bpp, &args->so.len, &args->so.end);
	args->we.w_pixel = mlx_get_data_addr(args->we.w_p,
			&args->we.bpp, &args->we.len, &args->we.end);
	args->ea.w_pixel = mlx_get_data_addr(args->ea.w_p,
			&args->ea.bpp, &args->ea.len, &args->ea.end);
	return (1);
}

static void	init_mlx(t_render *args)
{
	if (!init_window(args))
		close_win(args, 1);
	if (!get_img(args))
		close_win(args, 1);
	if (!get_wall(args, args->game))
		close_win(args, 1);
	set_position(args->game, args);
}
