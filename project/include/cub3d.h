/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:00:21 by yuak              #+#    #+#             */
/*   Updated: 2026/09/14 17:57:12 by yuak             ###   ########.fr       */
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


t_game	*init_game(char *cub);
int 	is_map_line(char *line);
size_t	get_map_size(char *cub);
int		assign_grid(t_map *map, char *cub);
t_map 	*extract_map(char *cub);
t_map	*init_map(char *cub);
int 	is_texture_line(char *line);
int 	assign_texture(t_game *game, char *line);
int 	get_texture_paths(char *cub, t_game *game);
int		read_next_line(int fd, char **line);

// Check Utils
void	print_error(char *str);
void	print_error_arg(char *str, char *arg);
size_t	get_splitted_size(char **splitted);
int		check_input(int ac, char **av);
int		check_identifiers(char *cub);
int		check_colors(char *cub);
int		check_invalid_line(char *cub);
int		is_there_map(char *cub);
int		is_map_position_true(char *cub);
int		get_player_position(t_game *game);
int		check_map(t_game *game);
char	**get_grid_copy(char **grid);
int		flood_fill(char **grid);
int		check_starting_position(char *cub);
int		is_map_line(char *line);

// free utils
void	free_split(char **splitted);
void	free_map(t_map *map);
void	free_grid(char **grid);
void	free_texture(t_texture texture);
void	free_game(t_game *game);

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