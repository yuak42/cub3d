/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:00:21 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:44:57 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "data.h"
#include <math.h>

#include "free.h" // delete this later


// Render
int		render(t_game *game);

// Delete later
void 	print_map(t_map *map);
void	print_texture_paths(t_game *game);
void	print_player_info(t_game *game);
void 	print_grid(char **grid);

void	set_dir(t_game *game);
void	set_position(t_game *game, t_render *args);
char	get_spawn_dir(t_game *game);
void	set_plane(t_game *game, t_render *args);
void	set_raydir(t_render *args, double x);
int		init_window(t_render *args);
void	set_map(t_render *args, t_game *game);
void	get_raycast_arg(t_game *game, t_render *args, int x);
void	run_dda(t_render *args, t_game *game, int x);
void	set_wall_size(t_render *args, t_game *game);
int		put_window(t_render *args, t_game *game, int x);
int		key_event(void *args);
void	ray_move(t_render *args);
int		close_win(t_render *args);
int		put_game(t_render *args);
int		key_release(int key_press, void *args);
int		key_press(int key_press, void *args);
void	move_pose(t_render *args);
void	free_render(t_render *args);
int		is_walkable(t_game *game, double x, double y);

#endif