/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:30:53 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:39:33 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "data.h"

t_map	*init_map(char *cub);
t_game	*init_game(char *cub);
int		assign_grid(t_map *map, char *cub);
t_map 	*extract_map(char *cub);
t_map	*init_map(char *cub);
int 	assign_texture(t_game *game, char *line);
int 	get_texture_paths(char *cub, t_game *game);
int		get_player_position(t_game *game);

#endif