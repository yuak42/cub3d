/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byaprak.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byaprak <byaprak@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:00:24 by yuak              #+#    #+#             */
/*   Updated: 2026/09/12 13:33:48 by byaprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

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