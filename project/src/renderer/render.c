/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:26:12 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 12:13:18 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_img(t_render *args);
static int	win_invisible(void *args);
//static int	x_win(t_render *args);

int	render(t_game *game)
{
	t_render *args;
	//t_win	*window;
	args = ft_calloc(sizeof(t_render), 1);
	if (!args)
		return(0);
	ft_printf("Game is being rendered\n");
	args->game = game;
	if (!init_window(args))
		return (0);
	// printf("dir_x:%f\ndir_y:%f\n", game->player.dir_x, game->player.dir_y);
	// printf("x:%f\ny:%f\n", game->player.x, game->player.y);
	// printf("plane_x:%f\nplane_y:%f\n", args->plane_x, args->plane_y);
	// printf("ray_dirx:%f\nray_diry:%f\n", args->ray_dirx, args->ray_diry);
	// printf("mapx:%d\nmapy:%d\n", args->mapx, args->mapy);
	// printf("deltadistx%f\ndeltadisty:%f\n", args->deltadistx, args->deltadisty);
	// printf("stepx:%d\nstepy:%d\n", args->stepx, args->stepy);
	// printf("sidedistx:%f\nsidedisty:%f\n", args->sidedistx, args->sidedisty);
	//printf("----------------width:%ld ********* height%ld--------\n", game->map->width, game->map->height);
	set_position(game, args);
	get_img(args);
	put_game(args);
	mlx_hook(args->window.win_ptr, 12, 1L << 15, win_invisible, args);
	mlx_hook(args->window.win_ptr, 17, 0, close_win, args);
	mlx_hook(args->window.win_ptr,  2, 1L << 0 , key_press, args);
	mlx_hook(args->window.win_ptr,  3, 1L << 1 , key_release, args);
	mlx_loop_hook(args->window.mlx_ptr, key_event, args);
	mlx_loop(args->window.mlx_ptr);
	return (0);
}

static int	get_img(t_render *args)
{
	args->img.img_p = mlx_new_image(args->window.mlx_ptr, args->window.w, args->window.h);
	if (!(args->img.img_p))
		return (0);
	args->img.img_pixel = mlx_get_data_addr(args->img.img_p, &args->img.bpp, &args->img.len, &args->img.end);
	return (1);
}

static int	win_invisible(void *args)
{
	t_render	*w;

	w = (t_render *)args;
	mlx_put_image_to_window(w->window.mlx_ptr, w->window.win_ptr, w->img.img_p, 0, 0);
	return (0);
}
