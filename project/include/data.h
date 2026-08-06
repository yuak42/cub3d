/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:17:12 by yuak              #+#    #+#             */
/*   Updated: 2026/08/06 12:52:27 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
} t_player;

typedef struct s_map
{
	char	**grid;
	size_t	width;
	size_t	height;
} t_map;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
} t_color;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_color	f;
	t_color	c;
} t_texture;



typedef struct s_game
{
	t_map		*map;
	t_player	player;
	t_texture	texture;
} t_game;

#endif