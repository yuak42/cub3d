/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:00:21 by yuak              #+#    #+#             */
/*   Updated: 2026/08/14 13:15:54 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Later libft headers update

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "data.h"
#include "byaprak.h"

int		check_input(int ac, char **av);
t_game	*init_game(char *cub);
int 	is_map_line(char *line);
size_t	get_map_size(char *cub);
int		assign_grid(t_map *map, char *cub);
t_map 	*extract_map(char *cub);
t_map	*init_map(char *cub);
int 	is_texture_line(char *line);
int 	assign_texture(t_game *game, char *line);
int 	get_texture_paths(char *cub, t_game *game);

// Check Utils
int		print_error(char *str);
int		check_texture_paths(char *cub);

// free utils
void	free_split(char **splitted);
void	free_game(t_game *game);

// Render
int		render(t_game *game);

// Delete later
void 	print_map(t_map *map);
void	print_texture_paths(t_game *game);

#endif