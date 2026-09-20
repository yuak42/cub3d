/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:10:34 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:45:43 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "data.h"

void	free_split(char **splitted);
void	free_map(t_map *map);
void	free_grid(char **grid);
void	free_texture(t_texture texture);
void	free_game(t_game *game);

#endif