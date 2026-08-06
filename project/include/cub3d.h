/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:00:21 by yuak              #+#    #+#             */
/*   Updated: 2026/06/27 22:29:51 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include "data.h"
#include "byaprak.h"

t_game	*parse(int ac, char **ar);
t_map	*create_map(char *cub);
int 	is_map_line(char *line);
size_t	get_map_size(char *cub);
void 	print_grid(char **grid);

// Render
int		render(t_game *game);

// Tests - Delete later
int	test_parser(t_game *game);


#endif