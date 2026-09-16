/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:54:11 by yuak              #+#    #+#             */
/*   Updated: 2026/09/16 17:33:05 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "data.h"

void	print_error(char *str);
void	print_error_arg(char *str, char *arg);
size_t	get_splitted_size(char **splitted);
int		check_input(int ac, char **av);
int		check_identifiers(char *cub);
int		check_colors(char *cub);
int		check_invalid_line(char *cub);
int		is_there_map(char *cub);
int		is_map_position_true(char *cub);
int		check_map(t_game *game);
int		flood_fill(char **grid);
int		check_starting_position(char *cub);
int		is_map_line(char *line);
char	**get_grid_copy(char **grid);
int		is_texture_line(char *line);

#endif