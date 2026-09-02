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

int	render(t_game *game)
{
	t_render *args;
	//t_win	*window;
	int		x;

	x = 0;
	args = ft_calloc(sizeof(t_render), 1);
	//window = ft_calloc(sizeof(t_win), 1);
	ft_printf("Game is being rendered\n");
	// set_dir(game);
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
	set_position(game);
	get_img(args);
	while (x < args->window.w)
	{
		get_raycast_arg(game, args, x);
		run_dda(args, game, x);
		x++;
	}
	printf("**********************************************************************************\n");
	mlx_put_image_to_window(args->window.mlx_ptr, args->window.win_ptr, args->img.img_p, 0, 0);
	printf("**********************************************************************************\n");
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