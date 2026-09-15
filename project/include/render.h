/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:37:15 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 16:54:36 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "data.h"

int		render(t_game *game);
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
int		close_win(t_render *args, int status);
int		put_game(t_render *args);
int		key_release(int key_press, void *args);
int		key_press(int key_press, void *args);
void	move_pose(t_render *args);
void	free_render(t_render *args);
int		is_walkable(t_game *game, double x, double y);

#endif