/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuak <yuak@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:17:12 by yuak              #+#    #+#             */
/*   Updated: 2026/09/15 10:45:31 by yuak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <stddef.h>

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

typedef struct s_xpm
{
	int	width;
	int	height;
} t_xpm;

typedef struct s_eventkey
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_key;
typedef struct s_walltexture
{
	char	*w_pixel;
	void	*w_p;
	int		tex_w;
	int		tex_h;
	int		bpp;
	int		len;
	int		end;
}	t_wall;

typedef struct s_image
{
	void	*img_p;
	char	*img_pixel;
	int		bpp;
	int		len;
	int		end;
}	t_img;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w;
	int		h;
}	t_win;

typedef struct s_put_size
{
	double	perpwalldist;
	int		lineheight;
	int		drawend;
	int		drawstart;
	double	wall_x;
	int		tex_x;
	int		side;
}	t_size;

typedef struct s_renderargs
{
	double	plane_x;
	double	plane_y;
	double	ray_dirx;
	double	ray_diry;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	double	sidedistx;
	double	sidedisty;
	double	dir_x;
	double	dir_y;
	int		flag;
	int		key_code;
	t_size	size;
	t_win	window;
	t_img	img;
	t_wall	no;
	t_wall	so;
	t_wall	ea;
	t_wall	we;
	t_wall	wall;
	t_game	*game;
	t_key	key;
}	t_render;

#endif
